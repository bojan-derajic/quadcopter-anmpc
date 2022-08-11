close all;

t = 0:Ta:T;

u1 = U(:, 1);
u2 = U(:, 2);
u3 = U(:, 3);
u4 = U(:, 4);

x = X(:, 1);
y = X(:, 2);
z = X(:, 3);
yaw = X(:, 9);

REF_x = REF(1:end-Np, 1);
REF_y = REF(1:end-Np, 2);
REF_z = REF(1:end-Np, 3);
REF_yaw = REF(1:end-Np, 4);

figure('Position', [10 50 650 500]);
plot3(REF_x, REF_y, REF_z, '--', 'color', [0.6350 0.0780 0.1840], 'linewidth', 1.5);
hold on;
grid on;
plot3(x, y, z, '-', 'color', [0 0.4470 0.7410], 'linewidth', 2);
axis('equal');
xlabel('x [m]');
ylabel('y [m]');
zlabel('z [m]');
view([-44, 15])
legend({'Referenca', 'ANMPC'},'position', [0.152615384615384,0.37709999961853,0.164514147194255,0.106000002288818])
%%
figure('Position', [10 0 500 650]);

subplot(4, 1, 1);
plot(t, REF_x, '--', 'color', [0.6350 0.0780 0.1840], 'linewidth', 1.5);
hold on;
grid on;
plot(t, x, '-', 'color', [0 0.4470 0.7410], 'linewidth', 1.5);
% xlabel('t [s]');
ylabel('x [m]');
legend({'Referenca', 'ANMPC'}, 'position', ...
        [0.25,0.935,0.536400005493164,0.025862069435308], 'Orientation', 'horizontal');

subplot(4, 1, 2);
plot(t, REF_y, '--', 'color', [0.6350 0.0780 0.1840], 'linewidth', 1.5);
hold on;
grid on;
plot(t, y, '-', 'color', [0 0.4470 0.7410], 'linewidth', 1.5);
% xlabel('t [s]');
ylabel('y [m]');
%legend({'Referenca', 'ANMPC', 'AANMPC'}, 'location', 'northwest');

subplot(4, 1, 3);
plot(t, REF_z, '--', 'color', [0.6350 0.0780 0.1840], 'linewidth', 1.5);
hold on;
grid on;
plot(t, z, '-', 'color', [0 0.4470 0.7410], 'linewidth', 1.5);
% xlabel('t [s]');
ylabel('z [m]');
%legend({'Referenca', 'ANMPC', 'AANMPC'}, 'location', 'northwest');

subplot(4, 1, 4);
plot(t, REF_yaw, '--', 'color', [0.6350 0.0780 0.1840], 'linewidth', 1.5);
hold on;
grid on;
plot(t, yaw, '-', 'color', [0 0.4470 0.7410], 'linewidth', 1.5);
xlabel('t [s]');
ylabel('\psi [rad]');
%legend({'Referenca', 'ANMPC', 'AANMPC'}, 'location', 'northwest');

figure('Position', [10 0 500 650]);

subplot(4, 1, 1);
plot(t(1:end-1), u1, '-', 'color', [0 0.4470 0.7410], 'linewidth', 1.5);
hold on;
grid on;
% xlabel('t [s]');
ylabel('u_1 [N]');
legend({'ANMPC'}, 'position', ...
        [0.25,0.935,0.536400005493164,0.025862069435308], 'Orientation', 'horizontal');

subplot(4, 1, 2);
plot(t(1:end-1), u2, '-', 'color', [0 0.4470 0.7410], 'linewidth', 1.5);
hold on;
grid on;
% xlabel('t [s]');
ylabel('u_2 [N]');
%legend({'ANMPC', 'AANMPC'}, 'location', 'southwest');

subplot(4, 1, 3);
plot(t(1:end-1), u3, '-', 'color', [0 0.4470 0.7410], 'linewidth', 1.5);
hold on;
grid on;
% xlabel('t [s]');
ylabel('u_3 [N]');
%legend({'ANMPC', 'AANMPC'}, 'location', 'southwest');

subplot(4, 1, 4);
plot(t(1:end-1), u4, '-', 'color', [0 0.4470 0.7410], 'linewidth', 1.5);
hold on;
grid on;
xlabel('t [s]');
ylabel('u_4 [N]');
%legend({'ANMPC', 'AANMPC'}, 'location', 'southwest');

E = REF(1:end-Np, :) - [x, y, z, yaw];
RMSE = sqrt(mean(E.^(2), 1));
disp('RMSE:')
disp(RMSE);

% MP = mean(U.^(2), 1);
% disp('Mean Control Signal Effort');
% disp(MP)
