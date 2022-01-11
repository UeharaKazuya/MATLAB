%% Calculate Control Point
function P = CalculateControlPoint(Q, u, k)
    nQ = length(Q);
    bMatrix = zeros(nQ,nQ); % ���֐��s��
    t_CalculateP = 0: nQ-1;      % ���֐����v�Z���邽�߂̃p�����[�^
    t_CalculateP = t_CalculateP / t_CalculateP(end);
    
    % t_CalculateP = t_CalculateP/t_CalculateP(end);
    for i = 1:nQ
         for j = 1:nQ
            bMatrix(i,j) = BasisFunction(u,j,k,t_CalculateP(i));
         end
    end

    P = zeros(nQ,2);  % ���o���鐧��_

    % paramater of lsqlin 
    % % % A�Ex <= b
    % % % Aeq�Ex = beq
    % % % lb<= x <= ub.
    
    lsqlin_Aeq = zeros(1,nQ);
    lsqlin_Aeq(1,1) = 1;
    
    lsqlin_beq = [Q(1,1)];
    lsqlin_lb = -10* ones(nQ,1);
    lsqlin_ub = 50* ones(nQ,1);
    P(:,1) = lsqlin(bMatrix, Q(:,1), [], [], lsqlin_Aeq, lsqlin_beq, lsqlin_lb, lsqlin_ub);

    lsqlin_beq = [Q(1,2)];
    lsqlin_lb = -10* ones(nQ,1);
    lsqlin_ub = 20* ones(nQ,1);
    P(:,2) = lsqlin(bMatrix, Q(:,2), [], [], lsqlin_Aeq, lsqlin_beq, lsqlin_lb, lsqlin_ub);

