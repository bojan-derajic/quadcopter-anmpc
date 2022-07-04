%% Nonlinear MPC Design for Quadcopter
create_nmpc_fcns
model_parameters

nx = 12;
ny = 4;
nu = 4;

NMPC = nlmpc(nx, ny, nu);

Ts = 0.2;
Np = 15;
Nc = 15;

NMPC.Ts = Ts;
NMPC.PredictionHorizon = Np;
NMPC.ControlHorizon = Nc;

NMPC.Model.StateFcn = @state_fcn;
NMPC.Jacobian.StateFcn = @state_jacob_fcn;
NMPC.Model.OutputFcn = @output_fcn;
NMPC.Jacobian.OutputFcn = @output_jacob_fcn;

NMPC.ManipulatedVariables = struct('Min', {0; 0; 0; 0}, 'Max', {8.5; 8.5; 8.5; 8.5});

NMPC.States(7).Min = -pi;
NMPC.States(7).Max = pi;
NMPC.States(8).Min = -pi/2;
NMPC.States(8).Max = pi/2;
NMPC.States(9).Min = -pi;
NMPC.States(9).Max = pi;

NMPC.OutputVariables(3).Min = 0;

NMPC.Weights.ManipulatedVariables = [1, 1, 1, 1];

NMPC.Weights.ManipulatedVariablesRate = [0, 0, 0, 0];

NMPC.Weights.OutputVariables = [1, 1, 3, 5];

NMPC.Optimization.UseSuboptimalSolution = true;
NMPC.Optimization.SolverOptions.MaxIterations = 200;

x0 = zeros(12, 1);
u0 = zeros(4, 1);

validateFcns(NMPC, x0, u0);

[coreData, onlineData] = getCodeGenerationData(NMPC, x0, u0, {});
onlineData.ref = zeros(Np, ny);

func = 'nlmpcmoveCodeGeneration';
func_output = 'nmpc_move';

Cfg = coder.config('mex');
Cfg.DynamicMemoryAllocation = 'off';
Cfg.ConstantInputs = 'IgnoreValues';

codegen('-config', Cfg, func, '-o', func_output, '-args',...
            {coder.Constant(coreData), x0, u0, onlineData});

% mexFcn = buildMEX(NMPC, 'NMPC_mex', coreData, onlineData);