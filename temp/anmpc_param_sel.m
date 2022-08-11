%%
figure('Position', [200, 200, 500, 300])
gamma_v = [0.5, 1, 3, 5, 7, 10, 15];
Ju_v = [0.001645, 0.001424, 0.001297, 0.001287, 0.001289, 0.001296, 0.001316];

plot(gamma_v, Ju_v, '-*', 'linewidth', 1);
grid on;
xlabel('\gamma', 'fontsize', 12);
ylabel('J_u', 'fontsize', 12);

%%
figure('Position', [200, 200, 500, 300])
gammaf_v = [1, 5, 10, 20, 30, 40, 50];
Ju_v = [0.001371, 0.001369, 0.001312, 0.001287, 0.001306, 0.001333, 0.001376];

plot(gammaf_v, Ju_v, '-*', 'linewidth', 1);
grid on;
xlabel('\gamma_f', 'fontsize', 12);
ylabel('J_u', 'fontsize', 12);

%%
figure('Position', [200, 200, 500, 300])
xi_v = [1, 3, 5, 10, 15, 20, 25];
Ju_v = [0.001962, 0.001513, 0.001344, 0.001287, 0.001310, 0.001342, 0.001377];

plot(xi_v, Ju_v, '-*', 'linewidth', 1);
grid on;
xlabel('\xi', 'fontsize', 12);
ylabel('J_u', 'fontsize', 12);

%%
figure('Position', [200, 200, 500, 300])
ae_v = [0.4, 0.5, 0.8, 1, 1.2, 1.5, 2];
Ju_v = [0.001380, 0.001375, 0.001303, 0.001287, 0.001293, 0.001315, 0.001361];

plot(ae_v, Ju_v, '-*', 'linewidth', 1);
grid on;
xlabel('a_e', 'fontsize', 12);
ylabel('J_u', 'fontsize', 12);

%%
figure('Position', [200, 200, 500, 300])
qe_v = [0.01, 0.05, 0.1, 0.2, 0.3, 0.4, 0.5];
Ju_v = [0.001614, 0.001539, 0.001379, 0.001287, 0.001322, 0.001361, 0.001372];

plot(qe_v, Ju_v, '-*', 'linewidth', 1);
grid on;
xlabel('q_e', 'fontsize', 12);
ylabel('J_u', 'fontsize', 12);