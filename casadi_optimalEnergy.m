%% 速度最適化

function [V, fval, exitflag, output,cout,ceqout] = casadi_optimalEnergy(t,DS,DS_2,DS_norm,R,Vmax,Amax,PosErrMax,Mass,Fmax,VelC,nt,ts,MotorRatio,SLength)
%%
MatMin = zeros(nt, 3);
for i = 1 :nt
    MatMin(i,1) = 2*(2*R(i)*PosErrMax)^(1/2) / ts;
    MatMin(i,2) = (SLength * Vmax/abs(DS(i,1)))^2;
    MatMin(i,3) = (SLength * Vmax/abs(DS(i,2)))^2;

    if MatMin(i,1) >= (MatMin(i,2))
        MatMin(i,1) = MatMin(i,2);
    end
    
    if MatMin(i,1) >= (MatMin(i,3))
        MatMin(i,1) = MatMin(i,3);
    end
end

%%
addpath('C:\Users\spica\OneDrive\大学\研究\matlab\matlab\casadi-windows-matlabR2016a-v3.5.5')
import casadi.*
opti = casadi.Opti();

V = opti.variable(nt);
opti.set_initial(, 2);

for i = 1:nt-1
    opti.subject_to( V <= MatMin(i,1) );
%     opti.subject_to( (DS_2(i,1)*(V(i)/SLength)^2 + DS(i,1)*(V(i+1)^2-V(i)^2)/2*SLength^2*(t(i+1)-t(i)))  <= Amax);
end

obj =  sum(Mass*abs(DS_2(i,1)*(V(i)/SLength)^2 + DS(i,1)*(V(i+1)^2-V(i)^2)/2*SLength^2*(t(i+1)-t(i))) + (VelC *V(i)));
opti.minimize( obj );

p_opts = struct('expand',true);
s_opts = struct('max_iter',10000);
opti.solver('ipopt',p_opts,s_opts);
sol = opti.solve();

%%
ffun = @f;
gfun = @g;
x0 = ones(nt,1);
x0 = x0.*Vmax;

for  i = 1:1
    x0(1,i) = 0;
    x0(2,i) = 0;
    x0(1,end-i+1) = 0;
    x0(2,end-i+1) = 0;
end

options = optimoptions('fmincon','Algorithm','interior-point','Display','iter','MaxFunctionEvaluations',100000000000, 'MaxIterations',10000000000);
% options = optimoptions('fmincon','Algorithm','interior-point','MaxFunctionEvaluations',100000000000);

[V, fval, exitflag, output] = fmincon(ffun,x0,[],[],[],[],[],[],gfun,options);

    function [fun] = f(V)
         fun =  -sum( (DS(:,1).*V./SLength).^2 + (MotorRatio.*DS(:,2).*V./SLength).^2 );
%          fun =  -sum(V.^2);
    end

    function [c, ceq] = g(V)
        for i = 2 : nt-1
%             c(i) = abs(DS_2(i,1)*(V(i)/DS_norm(i))^2 + DS(i,1)*((V(i+1)/DS_norm(i+1))^2-(V(i-1)/DS_norm(i-1))^2)/2*(t(i+1)-t(i-1))) - Amax;
%             c(nt+i) =abs(DS_2(i,2)*(V(i)/DS_norm(i))^2 + DS(i,2)*((V(i+1)/DS_norm(i+1))^2-(V(i-1)/DS_norm(i-1))^2)/2*(t(i+1)-t(i-1))) - Amax;
            c(i) = abs(DS_2(i,1)*(V(i)/SLength)^2 + DS(i,1)*(V(i+1)^2-V(i)^2)/2*SLength^2*(t(i+1)-t(i))) - Amax;
            c(nt+i) =abs(DS_2(i,2)*(V(i)/SLength)^2 + DS(i,2)*(V(i+1)^2-V(i)^2)/2*SLength^2*(t(i+1)-t(i))) - Amax;

            c(2*nt+i) = V(i) - MatMin(i,1);
            c(3*nt+i) = -V(i);
        end

        ceq(1) = V(1);
        ceq(nt) = V(nt);
    end

    [cout,ceqout] = g(V);
end