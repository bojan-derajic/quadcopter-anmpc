function ref = ref_traj(type, T, dt)
%REF_TRAJ generates reference trajectory for a quadcopter
    
    t = 0:dt:T;
    ref = zeros(T/dt, 4);
    
    if strcmp(type, 'lin') 
        ref(t>=0, :) = repmat([0, 0, 5, 0], sum(t>=0), 1);
        ref(t>=5, :) = repmat([0, -2, 5, 0], sum(t>=5), 1);
        ref(t>=10, :) = repmat([5, -2, 5, 0], sum(t>=10), 1);
        ref(t>=15, :) = repmat([5, -2, 5, 0.2], sum(t>=15), 1);
        ref(t>=20, :) = repmat([5, 4, 5, 0.2], sum(t>=20), 1);
        ref(t>=25, :) = repmat([5, 4, 0, 0.2], sum(t>=25), 1);
    elseif strcmp(type, 'circ')
        r = 2;
        ref(t>=0, 3) = 5;
        ref(t>=0, 2) = r;
        ref(t>=5, 1) = r*sin(4*pi/T*(t(t>=5)-5));
        ref(t>=5, 2) = r*cos(4*pi/T*(t(t>=5)-5));
    end
end

