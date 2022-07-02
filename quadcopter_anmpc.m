%% Adaptive Nonlinear MPC for Quadcopters
clear; close all; clc;

create_nmpc_controller;
%%
clc
T = 30;
dt = 0.001;
Ta = 0.005;

X = zeros(T/Ta+1, nx);
Xr = zeros(T/Ta+1, nx);
U = zeros(T/Ta, nu);
U_nmpc = zeros(T/Ta, nu);

mw = 21;
nw = 4;
W_data = zeros(mw, nw, T/Ta+1);
Wf_data = zeros(mw, nw, T/Ta+1);

x0 = zeros(12, 1);
u0 = zeros(4, 1);

W0 = [zeros(13, 4); eye(4, 4); -eye(4, 4)];
Wf0 = [zeros(13, 4); eye(4, 4); -eye(4, 4)];

gamma = 0.05;
gamma_f = 50;
ksi = 1000;

Ap = -eye(3);
Av = -eye(3);
Aeta = -eye(3);
Aomega = -eye(3);

Ae = 0.02*blkdiag(Ap, Av, Aeta, Aomega);

Q = 0.1*eye(12);

P = lyap(Ae, Q);

k = 1;
X(k, :) = x0;
Xr(k, :) = x0;
u_nmpc = u0;
W_data(:, :, k) = W0;
Wf_data(:, :, k) = Wf0;

REF = ref_traj('lin', T + Np*Ta, Ta);

hbar = waitbar(0,'Simulation Progress');
tic
for i = 1:T/Ts
    
    onlineData.ref = REF(k, :);
    x = X(k, :);
    Xr(k, :) = x;

    [u_nmpc, onlineData] = nmpc_move(coreData, x', u_nmpc, onlineData);
    
    for j = 1:Ts/Ta
        
        x = X(k, :);
        xr = Xr(k, :);
        e = x - xr;
        
        mu = Ae*e';
        
        phi = x(7);
        theta = x(8);
        psi = x(9);

        Rx = [1     0         0
              0  cos(phi)  -sin(phi)
              0  sin(phi)   cos(phi)];

        Ry = [cos(theta)  0   sin(theta)
                  0       1       0
              -sin(theta) 0   cos(theta)];

        Rz = [cos(psi)  -sin(psi)  0
              sin(psi)   cos(psi)  0
                 0          0      1];

        R = Rz*Ry*Rx;
        
        B = [zeros(3, 4); 1/m*R*B1; zeros(3, 4); J^(-1)*B2];
        
        xrd = state_fcn(xr', u_nmpc);
        
        ni = pinv(B)*(mu - state_fcn(x', u_nmpc) + xrd);
        
        sigma_delta = [1; x'];
        sigma_o = [sigma_delta; -u_nmpc];
        sigma = [sigma_o; ni];
        
        W = W_data(:, :, k);
        Wf = Wf_data(:, :, k);
        Wd = gamma*(sigma*e*P'*B - ksi*(W - Wf));
        Wfd = gamma_f*(W - Wf);
        
        W = W + Ta*Wd;
        Wf = Wf + Ta*Wfd;
        
        u = -W'*sigma;
        
        U(k, :) = u;
        U_nmpc(k, :) = u_nmpc;
        
        Xr(k+1, :) = xr + Ta*xrd';
        W_data(:, :, k+1) = W;
        Wf_data(:, :, k+1) = Wf;
        
        [t, x] = ode45(@(t, x) quadcopter_model(x, u, (k-1)*Ta), 0:dt:Ta, x);
    
        X(k+1, :) = x(end, :);
        
        k = k + 1;
    end
    
    waitbar(k*Ta/T,hbar);
end
toc

plot_trajectory;