%% Definition of quadcopter model's parameters
clear; close all; clc;

g = 9.81;

cT = 1.51*1e-6;
cM = 2.37*1e-8;
Tm = 0.0;
d = 0.14;
m = 0.75;

% JR = 1e-5;
Jxx = 0.0024;
Jyy = 0.0024;
Jzz = 0.0043;
J = diag([Jxx, Jyy, Jzz]);

B1 = [0 0 0 0
      0 0 0 0
      1 1 1 1];

B2 = [d*sqrt(2)/2  -d*sqrt(2)/2  -d*sqrt(2)/2  d*sqrt(2)/2
     -d*sqrt(2)/2  -d*sqrt(2)/2   d*sqrt(2)/2  d*sqrt(2)/2
        -cM/cT         cM/cT        -cM/cT        cM/cT];