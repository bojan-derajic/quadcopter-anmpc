model_parameters

syms x y z xd yd zd phi theta psi wx wy wz
syms u1 u2 u3 u4

p = [x; y; z];
v = [xd; yd; zd];
eta = [phi; theta; psi];
omega = [wx; wy; wz];

X = [p; v; eta; omega];
U = [u1; u2; u3; u4];

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
f(4:6) = [0; 0; -g] + 1/m*R*B1*U;
f(7:9) = T*omega;
f(10:12) = J^(-1)*(-cross(omega, J*omega) + B2*U);

f = vpa(simplify(transpose(f)), 8);
h = vpa(simplify([p; eta(3)]));

A = vpa(jacobian(f, X), 8);
B = vpa(jacobian(f, U), 8);
C = vpa(jacobian(h, X), 8);
D = vpa(jacobian(h, U), 8);

matlabFunction(f, 'File', 'state_fcn', 'Vars', {X, U});
matlabFunction(A, B, 'File', 'state_jacob_fcn', 'Vars', {X, U});
matlabFunction(h, 'File', 'output_fcn', 'Vars', {X, U});
matlabFunction(C, D, 'File', 'output_jacob_fcn', 'Vars', {X, U});

clear