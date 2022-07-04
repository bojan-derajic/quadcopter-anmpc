%% Nonlinear MPC for Quadcopters
clear; close all; clc;

create_nmpc_controller;
%%
clc
T = 30;
dt = 0.001;
Ta = 0.002;

X = zeros(T/Ta+1, nx);
UT = zeros(T/Ta+1, nu);
U = zeros(T/Ta, nu);

x0 = zeros(12, 1);
uT0 = zeros(4, 1);
u0 = zeros(4, 1);

onlineData.X0 = repmat(x0', Np, 1);
onlineData.MV0 = repmat(u0', Nc, 1);

k = 1;
X(k, :) = x0;
UT(k, :) = uT0;
u = u0;

REF = ref_traj('lin', T + Np*Ta, Ta);

hbar = waitbar(0,'Simulation Progress');
tic
for i = 1:T/Ts
    
    onlineData.ref = REF(k+1:k+Np, :);

    [u, onlineData] = nmpc_move(coreData, X(k, :)', u, onlineData);
    
    for j = 1:Ts/Ta
        
        s = [X(k, :), UT(k, :)];
        
        [t, s] = ode45(@(t, s) quadcopter_model(s, u, (k-1)*Ta), 0:dt:Ta, s);
        
        X(k+1, :) = s(end, 1:12);
        UT(k+1, :) = s(end, 13:16);
        U(k, :) = u;
        
        k = k + 1;
    end
    
    waitbar(k*Ta/T, hbar);
end
toc
close(hbar);

plot_trajectory;