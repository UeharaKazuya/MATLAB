%% ‘¬“xÅ“K‰»

function [V, fval, exitflag, output,cout,ceqout] = makeConstantOptimal(t,DS,DS_2,DS_norm,R,Vmax,Amax,PosErrMax,Mass,fmax,VelC,nt,ts,MotorRatio,SLength)
V = zeros(nt,1);

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

options = optimoptions('fmincon','Algorithm','interior-point','Display','iter','MaxFunctionEvaluations',30000, 'MaxIterations',0);
%options = optimoptions('fmincon','Algorithm','interior-point','MaxFunctionEvaluations',100000000000);

[V, fval, exitflag, output] = fmincon(ffun,x0,[],[],[],[],[],[],gfun,options);

%% Optimization conditions
    function [fun] = f(V)
         fun =  sum(Mass*(DS_2(i,1)*(V(i)/SLength)^2 + DS(i,1)*(V(i+1)^2-V(i)^2)/2*SLength^2*(t(i+1)-t(i)) - VelC*V(i)));
%          fun =  -sum(V.^2);
    end

    function [c, ceq] = g(V)
        for i = 2 : nt-1
%             c(i) = abs(DS_2(i,1)*(V(i)/DS_norm(i))^2 + DS(i,1)*((V(i+1)/DS_norm(i+1))^2-(V(i-1)/DS_norm(i-1))^2)/2*(t(i+1)-t(i-1))) - Amax;
%             c(nt+i) =abs(DS_2(i,2)*(V(i)/DS_norm(i))^2 + DS(i,2)*((V(i+1)/DS_norm(i+1))^2-(V(i-1)/DS_norm(i-1))^2)/2*(t(i+1)-t(i-1))) - Amax;
%             c(i) = abs(DS_2(i,1)*(V(i)/SLength)^2 + DS(i,1)*(V(i+1)^2-V(i)^2)/2*SLength^2*(t(i+1)-t(i))) - (fmax - VelC*V(i))/Mass;
%             c(nt+i) =abs(DS_2(i,2)*(V(i)/SLength)^2 + DS(i,2)*(V(i+1)^2-V(i)^2)/2*SLength^2*(t(i+1)-t(i))) - (fmax - VelC*V(i))/Mass;
            c(nt+i)   = 10 - sum(V.^2); 
            c(2*nt+i) = V(i) - MatMin(i,1);
            c(3*nt+i) = -V(i);
        end

        ceq(1) = V(1);
        ceq(nt) = V(nt);
    end

    [cout,ceqout] = g(V);
end