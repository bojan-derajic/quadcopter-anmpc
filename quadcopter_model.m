function f = quadcopter_model(x, u, t0)

g = 9.81;

% cT = 1.51*1e-6;
% cM = 2.37*1e-8;
% d = 0.14;
% m = 0.75;
% 
% Jxx = 0.0024;
% Jyy = 0.0024;
% Jzz = 0.0043;
% J = diag([Jxx, Jyy, Jzz]);

cT = 0.4*1e-6;
cM = 2.37*1e-8;
d = 0.22;
m = 1.4;

Jxx = 0.0024;
Jyy = 0.0024;
Jzz = 0.0043;
J = 3*diag([Jxx, Jyy, Jzz]);

if x(3) < 0
    x(3) = 0;
    x(6) = 0;
end

u(u>8.5) = 8.5;
u(u<0) = 0;

if t0 > 3
    u = [0.8; 1.3; 1.2; 0.7].*u;
end

if t0 > 7
    u = [0.3; 0.4; -0.25; -0.5] + u;
end

if t0 > 13
    m = 0.5;
end

Md = [0; 0; 0];
if t0 > 15
    Md = [0; 0.3; 0];
end

if t0 >= 21 && t0 <= 21.2
    u = u.*[1; 1; 0; 1];
end

if t0 > 25
    Md = Md + [0.3*sin(2*pi/2*t0); 0; 0];
end

B1 = [0  0  0  0
      0  0  0  0
      1  1  1  1];

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

f(1:3) = v;
f(4:6) = [0; 0; -g] + 1/m*R*B1*u;
f(7:9) = T*omega;
f(10:12) = J^(-1)*(-cross(omega, J*omega) + B2*u + Md);

f = f';
