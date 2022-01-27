%% main�֐��@���x�œK�����s���CB-Spline�Ȑ���\������D
clear

%% desired Points (X-Y)
% Q = [ 
%     0.0, 0.0;
%     1.0, 2.0;
%     3.0, 2.0;
%     3.0, 0.0;
%     5.0, 2.0;
%     6.0, 0.0;
%     ];
% 
% Q = [ 
%     0.0, 0.0;
%     0.0, 1.0;
%     0.0, 2.0;
%     0.0, 3.0;
%     0.0, 4.0;
%     0.0, 5.0;
%     5.0, 5.0;
%     5.0, 0.0;
%     0.0, 0.0;
%     ];

% Q = [
%     0.0, 0.0;
%     1.0, 1.0;
%     2.0, 2.0;
%     3.0, 3.0;
%     4.0, 4.0;
%     4.99, 4.99;
% %     5.0, 5.0;
%     5.01, 5.01;
%     6.0, 4.0;
%     7.0, 3.0;
%     8.0, 2.0;
%     9.0, 1.0;
%     10.0, 0.0;
%     9.0, -1.0;
%     8.0, -2.0;
%     7.0, -3.0;
%     6.0, -4.0;
%     5.0, -5.0;
%     4.0, -4.0;
%     3.0, -3.0;
%     2.0, -2.0;
%     1.0, -1.0;
%     0.0, 0.0;
%     ];

% Q = [
%     0.0, 0.0;
%     2.5, 2.5;
%     5.0, 5.0;
%     7.5, 2.5;
%     10.0, 0.0;
%     7.5, -2.5;
%     5.0, -5.0;
%     2.5, -2.5;
%     0.0, 0.0;
%     ];
    
%  
% Q = [ 
%     3.0, 0.0;
%     6.0, 3.0;
%     3.0, 6.0;
%     0.0, 3.0;
%     3.0, 0.0;
%     ];

% Q = [ 
%     0.0,   0.0;
%     10.0, 10.0;
%     10.0,  0.0;
%     0.0,  10.0;
%     0.0,   0.0;
%     ];

Q = [ 
    5.0, 0.0;
    10.0, 5.0;
    5.0, 10.0;
    0.0, 5.0;
    5.0, 0.0;
    ];


nQ = length(Q);     % Number of Control Points
k = 3;              % Degree of B-Spline
nKnot = nQ + k + 1; % Number of Knots in Knot Vector
nSampling = 50;     % Number of Sampling / Control Points
nt = nSampling * (nQ-1)+1;  % Number of Sampling
ts = 1;        % Sampling time [s]
Vmax = 1.1;        % max Velocity [m/s]
Amax = 150;          % max Accelaration [mm/s^2]
PosErrMax = 0.01;    % max Position Error [mm]
MotorRatio = 1;     % Ratio of Motor

Mass = 5.33;
% Mass = 0;
VelC = 24.2020;
Fmax = 100;


t = 0:nt-1;
t = t / t(end);
% Vmax = Vmax /60;   %[mm/min] to [mm/s]

u = OpenUniformKnotVector(nKnot,k,nQ);  %�J��l�m�b�g�x�N�g���쐬
P = CalculateControlPoint(Q, u, k); % ����_���o�֐�

%%  Calculate B-spline Curve
S = zeros(length(t),2);
for i = 1:length(t)
    for j =1:nQ
        b = BasisFunction(u,j,k,t(i));
        S(i,:) = S(i,:) + P(j,:)*b;
    end
end

S(1,:) = Q(1,:);
SLength = TotalLength(Q);

% figure;
% plot(S(:,1),S(:,2),P(:,1),P(:,2),'o',Q(:,1),Q(:,2),'o');

%% �����l���v�Z
DS = zeros(nt,2); % 1��ځFX���C2��ځFY��
% DS_norm = zeros(nt, 1);
DS_2 = zeros(nt,2); % 1��ځFX���C2��ځFY��
% DS_2_norm = zeros(nt, 1);

for i = 1: nt
    for j =1:nQ
        b = DifBasisFunction(1,u,j,k,t(i));  
        DS(i,:) = DS(i,:) + P(j,:)*b;
        DS_norm(i) = norm(DS(i,:));
        b = DifBasisFunction(2,u,j,k,t(i));  
        DS_2(i,:) = DS_2(i,:) + P(j,:)*b;
        DS_2_norm(i) = norm(DS_2(i,:));
    end
end

%% �ȗ�
for i = 1: nt
    for j =1:nQ
        MatDet = [DS(i, 1), DS(i, 2);
                  DS_2(i, 1), DS_2(i, 2)];
        R(i) = (DS(i,1)^2+DS(i,2)^2)^(3/2) / det(MatDet);
    end
end

%% ���x�œK��
DS_norm(1) = 1*10^(-10);
% [V, fval, exitflag,output, cout,ceqout] = optimalVelocityXYaxis(t,DS,DS_2,DS_norm,R,Vmax,Amax,PosErrMax,nt,ts,MotorRatio,SLength);
% [V, fval, exitflag,output, cout,ceqout] = optimalVelocityXZaxis(t,DS,DS_2,DS_norm,R,Vmax,Amax,PosErrMax,Fmax,Mass,VelC,nt,ts,MotorRatio,SLength);
% [V, fval, exitflag,output, cout,ceqout] = optimalVelocity(t,DS,DS_2,DS_norm,R,Vmax,Amax,PosErrMax,nt,ts,MotorRatio,SLength);
% [V, fval, exitflag,output, cout,ceqout] = optimalVelocityCXY(t,DS,DS_2,DS_norm,R,Vmax,Amax,PosErrMax,nt,ts,MotorRatio,SLength);
[V, fval, exitflag,output, cout,ceqout] = optimalEnergy(t,DS,DS_2,DS_norm,R,Vmax,Amax,PosErrMax,Fmax,Mass,VelC,nt,ts,MotorRatio,SLength);
% [V, fval, exitflag,output, cout,ceqout] = casadi_optimalVelocityXZaxis(t,DS,DS_2,DS_norm,R,Vmax,Amax,PosErrMax,Fmax,Mass,VelC,nt,ts,MotorRatio,SLength);
% [V, fval, exitflag,output, cout,ceqout] = casadi_optimalEnergy(t,DS,DS_2,DS_norm,R,Vmax,Amax,PosErrMax,Mass,Fmax,VelC,nt,ts,MotorRatio,SLength);


% min(cout)

%% ���x�v�Z
for i = 1: nt-1
    V(i,2) = DS(i,1)*V(i)./DS_norm(i);
    V(i,3) = DS(i,2)*V(i)./DS_norm(i);
    V(i,4) = norm(V(i,2:3));
end

%% �����x�v�Z
Accele = zeros(nt, 3);
for i = 2: nt-1
%     A(i, 1) = DS_2(i,1)*(V(i)/DS_norm(i))^2 + DS(i,1)*((V(i+1)/DS_norm(i+1))^2-(V(i-1)/DS_norm(i-1))^2)/2*(t(i+1)-t(i-1));
%     A(i, 2) = DS_2(i,2)*(V(i)/DS_norm(i))^2 + DS(i,2)*((V(i+1)/DS_norm(i+1))^2-(V(i-1)/DS_norm(i-1))^2)/2*(t(i+1)-t(i-1));
    
    Accele(i, 3) = (V(i+1)^2-V(i)^2) / 2*DS_norm(i)*(t(i+1)-t(i));
    Accele(i, 1) = -(DS_2(i,1)*(V(i)/DS_norm(i))^2 + DS(i,1)*Accele(i, 3)/DS_norm(i));
    Accele(i, 2) = DS_2(i,2)*(V(i)/DS_norm(i))^2 + DS(i,2)*Accele(i, 3)/DS_norm(i);
    
    Accele2(i, 1) = DS_2(i,1)*(V(i)/DS_norm(i))^2 + DS(i,1)*((V(i+1)/DS_norm(i+1))^2-(V(i-1)/DS_norm(i-1))^2)/2*(t(i+1)-t(i-1));
    Accele2(i, 2) = DS_2(i,2)*(V(i)/DS_norm(i))^2 + DS(i,2)*((V(i+1)/DS_norm(i+1))^2-(V(i-1)/DS_norm(i-1))^2)/2*(t(i+1)-t(i-1));
end

    Accele2(length(Accele2(:,1))+1, 1) = 0;

%% Plot result
% plot(t);

figure
subplot(2,1,1);
plot(t, V);
xlabel('t');
ylabel('V(m/s)');
legend('norm(original)','X-axis','Y-axis','norm(calculated)');


SRound = round(S,5).*(-1);
Feed = V.*60;
FeedRound = round(Feed,1);

subplot(2,1,1);
plot(t, Feed(:,2),'b-',t, Feed(:,3),'r--',t, Feed(:,1),'-.');
xlabel('u');
ylabel('V(mm/min)');
legend('X-axis','Y-axis','Feed','norm(calculated)');
set(gca, 'FontSize', 16);


subplot(2,1,2); 
plot(t, Accele(:,1),t, Accele(:,2),'--');
xlabel('u');
ylabel('A(m/s^2)');
legend('X-axis','Y-axis','Location','southeast');
set(gca, 'FontSize', 16);
% ylim([-120 120]);

% subplot(2,1,2); 
% plot(t, Accele2);
% xlabel('t');
% ylabel('A(m/s)');
% legend('X-axis','Y-axis');

% figure
% plot(t,DS(:, 1), t, DS(:, 2));
% xlabel('t');
% ylabel('dC/du');
% legend('dX','dY','d2X','d2Y');
% 
% figure
% plot(t,DS_2(:, 1), t, DS_2(:, 2));
% xlabel('t');
% ylabel('d^2C/du^2');
% legend('X','Y');

% 
% figure;
% plot(S(:,1),S(:,2),Q(:,1),Q(:,2),'kx',P(:,1),P(:,2),'o');
% set(gca, 'FontSize', 12);
% xlabel('X (mm)');
% ylabel('Y (mm)');
% legend('B-Spline curve','Desired navigation points','Control Points');
% axis equal;
% axis([-5 15 -1 20]);
% % 
% 
% NCCode = SRound;
% NCCode(:,3) = FeedRound(:,1);
%% �C���v�b�g�f�[�^���쐬
% close all;

%% ��葬�x���쐬
dt = 0.01;
Const_timeEnd = 15;
t = 0:dt:Const_timeEnd;
START_INDEX = 74;
END_INDEX   = 275;
CONST_VELOCITY = 0.8;
WIDTH_INDEX = 20;

Const.Pos = zeros(length(t), 2);
Const.Vel = zeros(length(t), 3);
Const.NormVel = zeros(length(V(:,1)),3);

Const.NormVel(:, 3) = CONST_VELOCITY;

Const.Vel(1:START_INDEX, 3) = 0;
Const.Vel(100:250, 3) = CONST_VELOCITY;

for i = 1:WIDTH_INDEX
    Const.NormVel(i, 3) = CONST_VELOCITY * (1 - cos((i-1) * pi/(WIDTH_INDEX-1)))/2;
end

for i = 1:WIDTH_INDEX
    Const.NormVel(i+length(V(:,1))-WIDTH_INDEX, 3) = CONST_VELOCITY * (1 + cos((i-1) * pi/(WIDTH_INDEX-1)))/2;
end

j = 3;
JUDGE_AXIS = 2;

for i = 1:length(t)
    if j > length(Const.NormVel(:,1))-1
        Const.Pos(i,:) = S(1,:);
        Const.Vel(i,:) = 0;
        
    else
        orientation = (S(j+1,:) - S(j,:))./norm(S(j+1,:) - S(j,:));
        Const.NormVel(j,1:2) = orientation * Const.NormVel(j,3);

        if i == 1
            Const.Pos(1,:) = S(1,:);
            Const.Vel(1,1:2) = [0, 0];
        elseif Const.NormVel(j,JUDGE_AXIS) < 0
            Const.Pos(i,:) = Const.Pos(i-1,:) + Const.NormVel(j,1:2).*dt;
            Const.Vel(i,1:2) = Const.NormVel(j,1:2);
            
            if Const.Pos(i,JUDGE_AXIS) < S(j,JUDGE_AXIS)
                if j < length(Const.Vel(:,1))
                    j = j+1;
                end
                Const.Pos(i,:) = S(j,:);
            end

        elseif Const.NormVel(j,JUDGE_AXIS) > 0
            Const.Pos(i,:) = Const.Pos(i-1,:) + Const.NormVel(j,1:2).*dt;
            Const.Vel(i,1:2) = Const.NormVel(j,1:2);

            if Const.Pos(i,JUDGE_AXIS) > S(j,JUDGE_AXIS)
                if j < length(Const.Vel(:,1))
                    j = j+1;
                end
                Const.Pos(i,:) = S(j,:);
            end
        elseif Const.NormVel(j,JUDGE_AXIS) == 0
            if j < length(Const.Vel(:,1))
                j = j+1;
            end            
        end        
    end
end

for i = 1:length(Const.Vel(:,1))
    Const.Vel(i,3) = norm(Const.Vel(i, 1:2));
end

figure;
subplot(3,1,1);
plot(t,Const.Vel(:,1),'b-',t,Const.Vel(:,2),'r--',t,Const.Vel(:,3));
xlabel('t');
ylabel('V(m/s)');
legend('X-axis','Y-axis','Feed','norm(calculated)');
set(gca, 'FontSize', 16);

subplot(3,1,2); 
plot(t,Const.Pos(:,1),'b-',t,Const.Pos(:,2),'r--');
xlabel('t');
ylabel('Pos(m)');
legend('X-axis','Y-axis','Location','southeast');
set(gca, 'FontSize', 16);

subplot(3,1,3); 
plot(Const.Pos(:,1),Const.Pos(:,2));
% xlabel('t');
% ylabel('Pos(m)');
% legend('X-axis','Y-axis','Location','southeast');
set(gca, 'FontSize', 16);


Const.Pos(:,1) = Const.Pos(:,1) - 5;

dt = 0.01;
Const_timeEnd = 3;
t = 0:dt:Const_timeEnd;

inputConstPosition = [t(:,1:283)', Const.Pos(924-75:1131,:)];
inputConstVelocity = [t(:,1:283)', Const.Vel(924-75:1131,1:2)];


for i = 1:START_INDEX
    inputConstVelocity(i, 2:3) = [0, 0];
end
for i = START_INDEX+1 : START_INDEX+2
    inputConstVelocity(i, 2:3) = inputConstVelocity(i+1, 2:3)./2;
end


for i = 1:START_INDEX+1
    inputConstPosition(i, 2:3) = [0, 0];
end
for i = END_INDEX : length(t)
    inputConstPosition(i, 2:3) = [0, 0];
end

for i = END_INDEX : length(t)
    inputConstVelocity(i, 2:3) = [0, 0];
end

inputConstPosition(:,1) = t';
inputConstVelocity(:,1) = t';


figure;
subplot(3,1,1);
plot(t,inputConstVelocity(:,2),'b-',t, inputConstVelocity(:,3),'r--');
xlabel('t');
ylabel('V(m/s)');
legend('X-axis','Y-axis','Feed','norm(calculated)');
set(gca, 'FontSize', 16);

subplot(3,1,2); 
plot(t,inputConstPosition(:,2),'b-',t,inputConstPosition(:,3),'r--');
xlabel('t');
ylabel('Pos(m)');
legend('X-axis','Y-axis','Location','southeast');
set(gca, 'FontSize', 16);

subplot(3,1,3); 
plot(Const.Pos(:,1),Const.Pos(:,2));
% xlabel('t');
% ylabel('Pos(m)');
% legend('X-axis','Y-axis','Location','southeast');
set(gca, 'FontSize', 16);


%% �œK��

T_data = t*15;
dt = 0.01;
t = 0:dt:Const_timeEnd;
j = 2;

realPosition = zeros(length(t),2);
realVelocity = zeros(length(t),2);

judgeAxis = 2;

for i = 1:length(t)
    if j > length(V(:,1)-1)
        realPosition(i,:) = NaN;
        realVelocity(i,:) = NaN;
        
    else
        if i == 1
            realPosition(1,:) = S(1,:);
            realVelocity(1,:) = V(1,2:3);
        elseif V(j,3) < 0
            realPosition(i,:) = realPosition(i-1,:) + V(j,2:3).*dt;
            realVelocity(i,:) = V(j,2:3);
            if realPosition(i,judgeAxis) < S(j,judgeAxis)
                if j < length(V(:,1))
                    j = j+1;
                end
                realPosition(i,:) = S(j,:);
            end

        elseif V(j,3) > 0
            realPosition(i,:) = realPosition(i-1,:) + V(j,2:3).*dt;
            realVelocity(i,:) = V(j,2:3);
            if realPosition(i,judgeAxis) > S(j,judgeAxis)
                if j < length(V(:,1))
                    j = j+1;
                end
                realPosition(i,:) = S(j,:);
            end
        end
        

    end
end

realPosition(:,1) = realPosition(:,1) - 5;


for i = 1:74
    realVelocity(i, 1:2) = [0, 0];
end
for i = 75:76
    realVelocity(i, 1:2) = realVelocity(i+1, 1:2)./2;
end
% for i = 198:301
%     realVelocity(i, 1:2) = [0, 0];
% end
for i = 1:74
    realPosition(i, 1:2) = [0, 0];
end
for i = 275:length(t)
    realPosition(i, 1:2) = [0, 0];
end

inputPosition = [t',realPosition];
inputVelocity = [t',realVelocity];


save('inputdata','inputPosition','inputVelocity','t','inputConstPosition','inputConstVelocity');

%%
% figure;
% subplot(2,1,1);
% plot(Real.Vel(:,1),Real.Vel(:,2),'b-',Real.Vel(:,1),Real.Vel(:,3),'r--');
% xlabel('t');
% ylabel('V(m/s)');
% legend('X-axis','Y-axis','Feed','norm(calculated)');
% set(gca, 'FontSize', 16);
% 
% 
% subplot(2,1,2); 
% plot(Real.Pos(:,1),Real.Pos(:,2),'b-',Real.Pos(:,1),Real.Pos(:,3),'r--');
% xlabel('t');
% ylabel('Pos(m)');
% legend('X-axis','Y-axis','Location','southeast');
% set(gca, 'FontSize', 16);


figure;
subplot(3,1,1);
plot(t,realVelocity(:,1),'b-',t,realVelocity(:,2),'r--');
xlabel('t');
ylabel('V(m/s)');
legend('X-axis','Y-axis','Feed','norm(calculated)');
set(gca, 'FontSize', 16);

subplot(3,1,2); 
plot(t,realPosition(:,1),'b-',t,realPosition(:,2),'r--');
xlabel('t');
ylabel('Pos(m)');
legend('X-axis','Y-axis','Location','southeast');
set(gca, 'FontSize', 16);

subplot(3,1,3); 
plot(realPosition(:,1),realPosition(:,2));
% xlabel('t');
% ylabel('Pos(m)');
% legend('X-axis','Y-axis','Location','southeast');
set(gca, 'FontSize', 16);

%%
clearvars b i Amax exitflag j k MatDet MotorRatio nKnot nQ nSampling nt output PosErrMax SLength ts u Vmax

% close all
return
 
%%
figure;
plot(S(:,1),S(:,2),Q(:,1),Q(:,2),'kx');
set(gca, 'FontSize', 14);
xlabel('X (mm)');
ylabel('Y (mm)');
legend('B-Spline curve','Desired navigation points');
axis equal;
axis([-5 15 -1 15]);

