close all;

t = 0:Ta:T;

u1_n = U_n(:, 1);
u2_n = U_n(:, 2);
u3_n = U_n(:, 3);
u4_n = U_n(:, 4);

x_n = X_n(:, 1);
y_n = X_n(:, 2);
z_n = X_n(:, 3);
yaw_n = X_n(:, 9);

REF_x = REF(1:end-Np, 1);
REF_y = REF(1:end-Np, 2);
REF_z = REF(1:end-Np, 3);
REF_yaw = REF(1:end-Np, 4);

figure('Position', [10 50 650 500]);
plot3(REF_x, REF_y, REF_z, '--', 'color', [0.6350 0.0780 0.1840], 'linewidth', 1.5);
hold on;
grid on;
plot3(x_n, y_n, z_n, '-.', 'color', [0.9290 0.6940 0.1250], 'linewidth', 2);
axis('equal');
xlabel('x [m]');
ylabel('y [m]');
zlabel('z [m]');
view([-44, 15])
legend({'Referenca', 'NMPC'},'position', [0.152615384615384,0.37709999961853,0.164514147194255,0.106000002288818])
%%
figure('Position', [10 0 500 650]);

subplot(4, 1, 1);
plot(t, REF_x, '--', 'color', [0.6350 0.0780 0.1840], 'linewidth', 1.5);
hold on;
grid on;
plot(t, x_n, '-.', 'color', [0.9290 0.6940 0.1250], 'linewidth', 1.5);
% xlabel('t [s]');
ylabel('x [m]');
legend({'Referenca', 'NMPC'}, 'position', ...
        [0.25,0.935,0.536400005493164,0.025862069435308], 'Orientation', 'horizontal');

subplot(4, 1, 2);
plot(t, REF_y, '--', 'color', [0.6350 0.0780 0.1840], 'linewidth', 1.5);
hold on;
grid on;
plot(t, y_n, '-.', 'color', [0.9290 0.6940 0.1250], 'linewidth', 1.5);
% xlabel('t [s]');
ylabel('y [m]');
%legend({'Referenca', 'NMPC', 'ANMPC'}, 'location', 'northwest');

subplot(4, 1, 3);
plot(t, REF_z, '--', 'color', [0.6350 0.0780 0.1840], 'linewidth', 1.5);
hold on;
grid on;
plot(t, z_n, '-.', 'color', [0.9290 0.6940 0.1250], 'linewidth', 1.5);
% xlabel('t [s]');
ylabel('z [m]');
%legend({'Referenca', 'NMPC', 'ANMPC'}, 'location', 'northwest');

subplot(4, 1, 4);
plot(t, REF_yaw, '--', 'color', [0.6350 0.0780 0.1840], 'linewidth', 1.5);
hold on;
grid on;
plot(t, yaw_n, '-.', 'color', [0.9290 0.6940 0.1250], 'linewidth', 1.5);
xlabel('t [s]');
ylabel('\psi [rad]');
%legend({'Referenca', 'NMPC', 'ANMPC'}, 'location', 'northwest');

figure('Position', [10 0 500 650]);

subplot(4, 1, 1);
plot(t(1:end-1), u1_n, '-.', 'color', [0.9290 0.6940 0.1250], 'linewidth', 1.5);
hold on;
grid on;
% xlabel('t [s]');
ylabel('u_1 [N]');
legend({'NMPC'}, 'position', ...
        [0.25,0.935,0.536400005493164,0.025862069435308], 'Orientation', 'horizontal');

subplot(4, 1, 2);
plot(t(1:end-1), u2_n, '-.', 'color', [0.9290 0.6940 0.1250], 'linewidth', 1.5);
hold on;
grid on;
% xlabel('t [s]');
ylabel('u_2 [N]');
%legend({'NMPC', 'ANMPC'}, 'location', 'southwest');

subplot(4, 1, 3);
plot(t(1:end-1), u3_n, '-.', 'color', [0.9290 0.6940 0.1250], 'linewidth', 1.5);
hold on;
grid on;
% xlabel('t [s]');
ylabel('u_3 [N]');
%legend({'NMPC', 'ANMPC'}, 'location', 'southwest');

subplot(4, 1, 4);
plot(t(1:end-1), u4_n, '-.', 'color', [0.9290 0.6940 0.1250], 'linewidth', 1.5);
hold on;
grid on;
xlabel('t [s]');
ylabel('u_4 [N]');
%legend({'NMPC', 'ANMPC'}, 'location', 'southwest');

E_n = REF(1:end-Np, :) - [x_n, y_n, z_n, yaw_n];
RMSE_n = sqrt(mean(E_n.^(2), 1));
disp('RMSE_n:')
disp(RMSE_n);

% MP = mean(U.^(2), 1);
% disp('Mean Control Signal Effort');
% disp(MP)
