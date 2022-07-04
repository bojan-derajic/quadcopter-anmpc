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
plot3(REF_x, REF_y, REF_z, 'r--', 'linewidth', 1.5);
hold on;
grid on;
plot3(x, y, z, 'b', 'linewidth', 2);
axis('equal');
xlabel('x');
ylabel('y');
zlabel('z');
legend({'Reference', 'True position'})

figure('Position', [10 0 500 1000]);

subplot(4, 1, 1);
plot(t, REF_x, 'r--', 'linewidth', 1);
hold on;
grid on;
plot(t, x, 'b', 'linewidth', 1);
xlabel('t [s]');
ylabel('x [m]');
legend({'Reference', 'True Position'}, 'location', 'southwest');

subplot(4, 1, 2);
plot(t, REF_y, 'r--', 'linewidth', 1);
hold on;
grid on;
plot(t, y, 'b', 'linewidth', 1);
xlabel('t [s]');
ylabel('y [m]');
legend({'Reference', 'True Position'}, 'location', 'southwest');

subplot(4, 1, 3);
plot(t, REF_z, 'r--', 'linewidth', 1);
hold on;
grid on;
plot(t, z, 'b', 'linewidth', 1);
xlabel('t [s]');
ylabel('z [m]');
legend({'Reference', 'True Position'}, 'location', 'southwest');

subplot(4, 1, 4);
plot(t, REF_yaw, 'r--', 'linewidth', 1);
hold on;
grid on;
plot(t, yaw, 'b', 'linewidth', 1);
xlabel('t [s]');
ylabel('yaw [rad]');
legend({'Reference', 'True angle'}, 'location', 'northwest');

figure('Position', [10 0 500 1000]);

subplot(4, 1, 1);
plot(t(1:end-1), u1, 'b', 'linewidth', 1);
grid on;
xlabel('t [s]');
ylabel('u1 [N]');

subplot(4, 1, 2);
plot(t(1:end-1), u2, 'b', 'linewidth', 1);
grid on;
xlabel('t [s]');
ylabel('u2 [N]');

subplot(4, 1, 3);
plot(t(1:end-1), u3, 'b', 'linewidth', 1);
grid on;
xlabel('t [s]');
ylabel('u3 [N]');

subplot(4, 1, 4);
plot(t(1:end-1), u4, 'b', 'linewidth', 1);
grid on;
xlabel('t [s]');
ylabel('u4 [N]');

E = REF(1:end-Np, :) - [x, y, z, yaw];
RMSE = sqrt(mean(E.^(2), 1));
disp('RMSE:')
disp(RMSE);

MP = mean(U.^(2), 1);
disp('Mean Control Signal Effort');
disp(MP)
