function f = quadcopter_model(s, u, t0)

g = 9.81;

cT = 1.51*1e-6;
cM = 2.37*1e-8;
Tm = 0.00005;
d = 0.14;
m = 0.75;

% JR = 1e-5;
Jxx = 0.0024;
Jyy = 0.0024;
Jzz = 0.0043;
J = diag([Jxx, Jyy, Jzz]);

% if t0 > 3
%     u = [1; 0.8; 1; 0.7].*u;
% elseif t0 > 7
%     u = [1; 1.2; 1.6; 1.7].*u;
% end
% 
% if t0 > 17
%     u = u + [0; -0.1; 0; 0.15];
%     m = 0.5;
% end

% if t0 >= 17 && t0 <= 17.2
%     u = u.*[1; 1; 0; 1];
% end

x = s(1:12);
uT = s(13:16);

B1 = [0 0 0 0
      0 0 0 0
      1 1 1 1];

B2 = [d*sqrt(2)/2  -d*sqrt(2)/2  -d*sqrt(2)/2  d*sqrt(2)/2
     -d*sqrt(2)/2  -d*sqrt(2)/2   d*sqrt(2)/2  d*sqrt(2)/2
        -cM/cT         cM/cT        -cM/cT        cM/cT];

v = x(4:6);
omega = x(10:12);

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

T = [1  tan(theta)*sin(phi)  tan(theta)*cos(phi)
     0       cos(phi)             -sin(phi)
     0  sin(phi)/cos(theta)  cos(phi)/cos(theta)];

u(u>8.5) = 8.5;
u(u<0) = 0;

f(1:3) = v;
f(4:6) = [0; 0; -g] + 1/m*R*B1*u;
f(7:9) = T*omega;
f(10:12) = J^(-1)*(-cross(omega, J*omega) + B2*u);
f(13:16) = -1/Tm*uT + 1/Tm*u;

f = f';
