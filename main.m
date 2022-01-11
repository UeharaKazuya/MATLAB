%% main関数　速度最適化を行い，B-Spline曲線を表示する．
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
Vmax = 1000;        % max Velocity [mm/min]
Amax = 150;          % max Accelaration [mm/s^2]
PosErrMax = 0.5;    % max Position Error [mm]
MotorRatio = 1;     % Ratio of Motor

Mass = 5;
VelC = 5;
Fmax = 10;


t = 0:nt-1;
t = t / t(end);
Vmax = Vmax /60   %[mm/min] to [mm/s]

u = OpenUniformKnotVector(nKnot,k,nQ);  %開一様ノットベクトル作成
P = CalculateControlPoint(Q, u, k); % 制御点導出関数

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


plot(S(:,1),S(:,2),P(:,1),P(:,2),'o',Q(:,1),Q(:,2),'o');

%% 微分値を計算
DS = zeros(nt,2); % 1列目：X軸，2列目：Y軸
% DS_norm = zeros(nt, 1);
DS_2 = zeros(nt,2); % 1列目：X軸，2列目：Y軸
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

%% 曲率
for i = 1: nt
    for j =1:nQ
        MatDet = [DS(i, 1), DS(i, 2);
                  DS_2(i, 1), DS_2(i, 2)];
        R(i) = (DS(i,1)^2+DS(i,2)^2)^(3/2) / det(MatDet);
    end
end

%% 速度最適化
DS_norm(1) = 1*10^(-10);
% [V, fval, exitflag,output, cout,ceqout] = optimalVelocityXYaxis(t,DS,DS_2,DS_norm,R,Vmax,Amax,PosErrMax,nt,ts,MotorRatio,SLength);
[V, fval, exitflag,output, cout,ceqout] = optimalVelocityXZaxis(t,DS,DS_2,DS_norm,R,Vmax,Amax,PosErrMax,Fmax,Mass,VelC,nt,ts,MotorRatio,SLength);
% [V, fval, exitflag,output, cout,ceqout] = optimalVelocity(t,DS,DS_2,DS_norm,R,Vmax,Amax,PosErrMax,nt,ts,MotorRatio,SLength);
% [V, fval, exitflag,output, cout,ceqout] = optimalVelocityCXY(t,DS,DS_2,DS_norm,R,Vmax,Amax,PosErrMax,nt,ts,MotorRatio,SLength);
% [V, fval, exitflag,output, cout,ceqout] = optimalEnergy(t,DS,DS_2,DS_norm,R,Vmax,Amax,PosErrMax,Fmax,Mass,VelC,nt,ts,MotorRatio,SLength);


% min(cout)

%% 速度計算
for i = 1: nt-1
    V(i,2) = DS(i,1)*V(i)/SLength;
    V(i,3) = DS(i,2)*V(i)/SLength;
    V(i,4) = norm(V(i,2:3));
end

%% 加速度計算
Accele = zeros(nt, 3);
for i = 2: nt-1
%     A(i, 1) = DS_2(i,1)*(V(i)/DS_norm(i))^2 + DS(i,1)*((V(i+1)/DS_norm(i+1))^2-(V(i-1)/DS_norm(i-1))^2)/2*(t(i+1)-t(i-1));
%     A(i, 2) = DS_2(i,2)*(V(i)/DS_norm(i))^2 + DS(i,2)*((V(i+1)/DS_norm(i+1))^2-(V(i-1)/DS_norm(i-1))^2)/2*(t(i+1)-t(i-1));
    
    Accele(i, 3) = (V(i+1)^2-V(i)^2) / 2*SLength*(t(i+1)-t(i));
    Accele(i, 1) = DS_2(i,1)*(V(i)/SLength)^2 + DS(i,1)*Accele(i, 3)/SLength;
    Accele(i, 2) = DS_2(i,2)*(V(i)/SLength)^2 + DS(i,2)*Accele(i, 3)/SLength;
    
    Accele2(i, 1) = DS_2(i,1)*(V(i)/DS_norm(i))^2 + DS(i,1)*((V(i+1)/DS_norm(i+1))^2-(V(i-1)/DS_norm(i-1))^2)/2*(t(i+1)-t(i-1));
    Accele2(i, 2) = DS_2(i,2)*(V(i)/DS_norm(i))^2 + DS(i,2)*((V(i+1)/DS_norm(i+1))^2-(V(i-1)/DS_norm(i-1))^2)/2*(t(i+1)-t(i-1));
end

    Accele2(length(Accele2(:,1))+1, 1) = 0;

%% Plot result
% plot(t);

% figure
subplot(2,1,1);
plot(t, V);
xlabel('t');
ylabel('V(m/s)');
legend('norm(original)','X-axis','Y-axis','norm(calculated)');

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

SRound = round(S,5).*(-1);
Feed = V.*60;
FeedRound = round(Feed,1);

subplot(2,1,1);
plot(t, Feed(:,2),'b-',t, Feed(:,3),'r--',t, Feed(:,1),'-.');
xlabel('u');
ylabel('V(mm/min)');
legend('X-axis','Y-axis','Feed','norm(calculated)');
set(gca, 'FontSize', 16);

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

%%
clearvars b i Amax exitflag fval j k MatDet MotorRatio nKnot nQ nSampling nt output P PosErrMax SLength ts u Vmax

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

