%% Nonlinear MPC for Quadcopters
% clear; close all; clc;
% 
% create_nmpc_controller;

T = 30;
dt = 0.001;
Ta = 0.002;

X_n = zeros(T/Ta+1, nx);
U_n = zeros(T/Ta, nu);

x0 = zeros(12, 1);
u0 = zeros(4, 1);

onlineData.X0 = repmat(x0', Np, 1);
onlineData.MV0 = repmat(u0', Nc, 1);

k = 1;
X_n(k, :) = x0;
u = u0;

REF = ref_traj('comb', T + Np*Ta, Ta);

hbar = waitbar(0,'Simulation Progress');
tic
for i = 1:T/Ts
    
    onlineData.ref = REF(k+1:k+Np, :);

    [u, onlineData] = nmpc_move(coreData, X_n(k, :)', u, onlineData);
    
    for j = 1:Ts/Ta
        
        x = X_n(k, :);
        
        [t, x] = ode45(@(t, x) quadcopter_model(x, u, (k-1)*Ta), 0:dt:Ta, x);
        
        X_n(k+1, :) = x(end, :);
        U_n(k, :) = u;
        u
        
        k = k + 1;
    end
    
    waitbar(k*Ta/T, hbar);
end
toc
close(hbar);

% plot_trajectory;