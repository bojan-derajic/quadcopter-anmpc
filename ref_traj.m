function ref = ref_traj(type, T, dt)
%REF_TRAJ generates reference trajectory for a quadcopter
    
    t = 0:dt:T;
    ref = zeros(T/dt, 4);
    
    if strcmp(type, 'lin') 
        ref(t>0, :) = repmat([0, 0, 5, 0], sum(t>0), 1);
        ref(t>=5, :) = repmat([0, -2, 5, 0], sum(t>=5), 1);
        ref(t>=10, :) = repmat([5, -2, 5, 0], sum(t>=10), 1);
        ref(t>=15, :) = repmat([5, -2, 5, pi/3], sum(t>=15), 1);
        ref(t>=20, :) = repmat([5, 4, 5, pi/3], sum(t>=20), 1);
        ref(t>=25, :) = repmat([5, 4, 0, pi/3], sum(t>=25), 1);
    elseif strcmp(type, 'comb')
        ref(t>0, :) = repmat([0, 0, 2, 0], sum(t>0), 1);
        ref(t>=5, :) = repmat([0, -2, 2, 0], sum(t>=5), 1);
        
        ref(t>=10, 1) = 2*sin(pi/10*(t(t>=10)-10));
        ref(t>=10, 2) = -2*cos(pi/10*(t(t>=10)-10));
        ref(t>=10, 3) = 0.2*t(t>=10) + 1;
        
        ref(t>=15, :) = repmat([2, 0, 4, 0], sum(t>=15), 1);
        
        ref(t>=17, :) = repmat([2, 2, 4, 0], sum(t>=17), 1);
        
        ref(t>=20, 1) = 2*sqrt(2)*cos(3*pi/20*(t(t>=20)-20) + pi/4);
        ref(t>=20, 2) = 2*sqrt(2)*sin(3*pi/20*(t(t>=20)-20) + pi/4);
        ref(t>=20, 4) = pi/3;
        
        ref(t>=25, :) = repmat([-2*sqrt(2), 0, 4, pi/3], sum(t>=25), 1);
        
        ref(t>=27, :) = repmat([-2*sqrt(2), 0, 0, pi/3], sum(t>=27), 1);
    elseif strcmp(type, 'circ')
        r = 5;
        ref(t>=0, 3) = 5;
        ref(t>=0, 2) = r;
        ref(t>=5, 1) = r*sin(0.5*(t(t>=5)-5));
        ref(t>=5, 2) = r*cos(0.5*(t(t>=5)-5));
    elseif strcmp(type, 'hel')
        r = 5;
        ref(t>=0, 3) = t*10/T;
        ref(t>=0, 2) = r;
        ref(t>=5, 1) = r*sin(2*pi/10*(t(t>=5)-5));
        ref(t>=5, 2) = r*cos(2*pi/10*(t(t>=5)-5));
    end
end

