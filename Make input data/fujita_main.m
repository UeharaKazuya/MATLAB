%-------------����------------
%  max_err�F���e�덷
%�@Q�F�ڕW���W
%  k�FB-Spline�̎���
%  n_sampling�F�P�̃Z�O�����g�������̗��U�_�ō\�����邩
%�@Vmax����Jmin�F���x�C�����x�C�W���[�N�̍ő�l�C�ŏ��l
%  dt�F���̓f�[�^�����ۂ̗��U����
%-----------------------------


%-------------�o��------------
%�@Real_Pos_data�F���̓f�[�^�F0.01�b�idt�b�j���Ƃɓ��̓f�[�^��������悤�ɐ��`��������
%�@Real_Pos_repeat�F��̃f�[�^���J��Ԃ������́D���̃v���O���������������č��͂ł��ĂȂ��ł��@���݂܂���
%  figure(1)�F�œK�o�H
%  figure(2)�F�œK���x
%  figure(3)�F�œK���葬�x
%  figure(4)�F�œK�����x
%  figure(5)�F�œK�W���[�N
%  figure(6)�F�œK���U����
%  figure(7)�F���ꂼ��𐳋K�����Đ�������͈̔͂�
% �@�@�@�@�@�@�����Ă��邩��ڂŊm�F���邽�߂̃O���t
%-----------------------------


%---------�֐��̐���-----------------------------------------------------------
%  loadlib�F�K�v�ȃ��C�u������ǂݍ��ނ��߂̂��́i�e���̃t�H���_���w��j
%  Knot�F�m�b�g�x�N�g���̌v�Z

%  WichSpan�FB-Spline�̃X�p�����v�Z���Ċ��֐��̌v�Z�ɕK�v�ȃp�����[�^�����߂�
%  Calc_BasisFunc�FB-Spline���֐��̌v�Z
%  DersBasisFuns�F���֐�������������

%  create_bound�Ffigure(1)�̐����͈͂��v���b�g���邽�߂ɕK�v�ȃf�[�^�𐶐��i��ώG�ɍ쐬�����̂Ō��Â炢�j
%  Calc_RealTime_Linear�F���̓f�[�^�̐����@�΂�΂�̗��U���ԂŐ������ꂽ�f�[�^����`�⊮���ē��Ԋu�̗��U���Ԃŕ\��������
%  Make_RealPosData�F���̓f�[�^���J��Ԃ��������������́i���͓����ĂȂ��CReal_Pos_data���J��Ԃ��z��Ɋi�[���邾���Ȃ̂ő債�����͏����ĂȂ��j
%  ToTalLength�F�O��S�̒������v�Z�������
%--------------------------------------------------------------------------------

clear 
close all
clc

loadlib

Q = [ 
    0,0;
    0,-5;
    0.5,-5;
];
max_err = 0.5;    % max Position Error [mm]
MotorRatio = 1;     % Ratio of Motor
k = 3;
n_sampling = 50;
dt = 0.01;%0.01[sec] ���̓f�[�^�Ƃ��ė��U����dt���Ƃɐ��`�⊮����Ƃ��ɗ��p

%---�œK�����邽�� �ɕω�������l�̏㉺���ݒ�---
Vmax = [1, 1];%x,y [mm/sec]
Vmin = -Vmax;
Amax = [10,10]; %[mm/s^2]
Amin = -Amax;
Jmax = [100, 100]; %[mm/s^3]
Jmin = -Jmax;



%------�œK���ϐ�P �̒�`---------
opti = casadi.Opti();
x = opti.variable(length(Q)*3);
y = opti.variable(length(Q)*3);
P = [x,y];


nQ = length(P);
n_segment = nQ-1;

nt = n_sampling * n_segment+1;
nKnot = n_segment-k + (k + 1)*2;

t = 0:nt-1;
t = t / t(end);

% Mass = 5;
% VelC = 5;
% Fmax = 10;
u = Knot(nKnot,k,nQ);  %�J��l�m�b�g�x�N�g���쐬


%%  Calculate B-spline

%-----------�e���U���Ԃł̒l�̏ꍇ��B-Spline--------------
bMatrix_risan = zeros(nt,nQ); % �e����_�ɂ�������֐��̒l
DbMatrix_risan = zeros(nt,nQ);
DDbMatrix_risan = zeros(nt,nQ);
DDDbMatrix_risan = zeros(nt,nQ);

for Time_Index = 1:length(t)
    Span_Index = WhichSpan(t(Time_Index), u, k);
    
    if t(Time_Index) == 1
        bMatrix_risan(Time_Index,:) = flip(bMatrix_risan(1,:));
        DbMatrix_risan(Time_Index,:) = -flip(DbMatrix_risan(1,:));
        DDbMatrix_risan(Time_Index,:) = flip(DDbMatrix_risan(1,:));
        DDDbMatrix_risan(Time_Index,:) = -flip(DDDbMatrix_risan(1,:));        
    else
        Ders = DersBasisFuns(t(Time_Index), Span_Index, k, 3, u);
        bMatrix_risan(Time_Index,(Span_Index-k):Span_Index) = Ders(1,:);
        DbMatrix_risan(Time_Index,(Span_Index-k):Span_Index) = Ders(2,:);
        DDbMatrix_risan(Time_Index,(Span_Index-k):Span_Index) = Ders(3,:);
        DDDbMatrix_risan(Time_Index,(Span_Index-k):Span_Index) = Ders(4,:);
    end
end

% �e����_�̍��W�ɂ�����B-Spline��S�A����DS�A2�K����DDS�C�R�K����DDDS
S = bMatrix_risan*P;
DS = DbMatrix_risan*P;
DDS = DDbMatrix_risan*P;
DDDS = DDDbMatrix_risan*P;

%% �ȗ�
for i = 1: nt
    for j =1:nQ
        dif_data = [DS(i, 1), DS(i, 2);
        DDS(i, 1), DDS(i, 2)];%x��y�̔�����2�K����
        R(i) = {(DS(i,1)^2+DS(i,2)^2)^(3/2) / det(dif_data)};
    end
end
%% -------------�e�T���v���_�Ԃ̎��ԍŏ���----------------------
% T_opt�͂��ꂼ��dT�����߂Ĉ�Z�O�����g�����ׂđ������킹�邱�ƂŊe���쎞��T���ŏ�������Ƃ�������ɂȂ�

T = opti.variable(nt);% �œK���ϐ��̐ݒ�
%opti.set_initial(T,zeros(1,nt));

for i = 1:length(Q)
    opti.set_initial(x(i*3-2),Q(i,1));
    opti.set_initial(y(i*3-2),Q(i,2));
    opti.set_initial(x(i*3-1),Q(i,1));
    opti.set_initial(y(i*3-1),Q(i,2));
    opti.set_initial(x(i*3),Q(i,1));
    opti.set_initial(y(i*3),Q(i,2));
end
%----- �ړI�֐��̐ݒ� ------------- 
obj = sum(T);% �ʂ�opti.minimize(sum(T));�ł��������ǌ��ʂ��v���b�g����Ƃ��ړI�֐����Ăяo���Ȃ�����s��
opti.minimize(obj);


%�n�_�ƏI�_�Œ�~����Ƃ�������
for i = 1:nt
    opti.subject_to(Vmin(1)*T(i) <= DS(i,1));
    opti.subject_to(Vmin(2)*T(i) <= DS(i,2)); %B-SPline�ɂ͎��Ԃ̊T�O�������Ă��Ȃ��̂ŁA���������Vmax,Vmin��g�ݍ��ލہA�����������Ď�荞�ޕK�v������B
    opti.subject_to(Vmax(1)*T(i) >= DS(i,1)); %���̂��߁AVmin[mm/s]*T[s] = V[mm/��]�Ɩ��������������x�p�����[�^�ɂ��Ă��� 
    opti.subject_to(Vmax(2)*T(i) >= DS(i,2));
%     
     opti.subject_to(Amin(1)*T(i)^2 <= DDS(i,1));
     opti.subject_to(Amin(2)*T(i)^2 <= DDS(i,2));
     opti.subject_to(Amax(1)*T(i)^2 >= DDS(i,1));
     opti.subject_to(Amax(2)*T(i)^2 >= DDS(i,2));
%
     opti.subject_to(Jmin(1)*T(i)^3 <= DDDS(i,1));
     opti.subject_to(Jmin(2)*T(i)^3 <= DDDS(i,2));
     opti.subject_to(Jmax(1)*T(i)^3 >= DDDS(i,1));
     opti.subject_to(Jmax(2)*T(i)^3 >= DDDS(i,2));
end
% ------�X�^�[�g�ƏI���̓_��ʂ�悤�ɐ���
opti.subject_to({x(1)==Q(1,1),y(1)==Q(1,2)});
opti.subject_to({x(end)==Q(end,1),y(end)==Q(end,2)});
% ------ �~�͈͓̔��ɐ��� ----------------
for i = 1:length(Q)
    opti.subject_to(max_err^2 >= ((x(i*3-2)-Q(i,1)).^2 + (y(i*3-2)-Q(i,2)).^2))
    opti.subject_to(max_err^2 >= ((x(i*3-1)-Q(i,1)).^2 + (y(i*3-1)-Q(i,2)).^2))
    opti.subject_to(max_err^2 >= ((x(i*3)-Q(i,1)).^2 + (y(i*3)-Q(i,2)).^2))
end
% -------------- �ŏI�Z�O�����g�Œ�~����Ƃ������� ----------
opti.subject_to(x(1)==x(2));
opti.subject_to(y(1)==y(2));
opti.subject_to(x(end-1)==x(end));
opti.subject_to(y(end-1)==y(end));

%% ---------------����܂łɒ�`����������p���čœK�������������� ---------

%---�\���o�[�̃I�v�V�����ݒ� --------
p_opts = struct('expand',true);
s_opts = struct('max_iter',10000);
opti.solver('ipopt',p_opts,s_opts);
sol = opti.solve();

% �œK���������U���Ԃ̊i�[
T_opt = sol.value(T);

%% ------plot result---------
%T_data�͊e���U����T�̒ʂ�ω������Ƃ��̎��Ԃ�\��
%nt�Ŋ����Ă���̂�T*Vmin<=DS<=T*Vmax�Ƃ������Ɋ֌W����BDS�͌v�Z��ł�{S(i+1)-S(i)}/(1/nt)�ł���B����͍ő厞�Ԃ��P�Ƃ������K�����ꂽ���Ԏ��ŕ\����邽�߂ł���B
%���̂��߁ADS�����߂邽�߂ɃT���v����nt�őS�̎��ԂP�𕪊���������(1/nt)�Ԋu�Ŕ������Ă���Ƃ킩��B
%�œK���ŋ��߂�T�Ƃ����l�͐��K�����ꂽ�e���U����(1/nt)��T�Ƃ����l�Ɉ������΂��Ƃ������̂ł���B

T_opt = T_opt/nt;
for i = 1:length(sol.value(T))
    T_data(i) = sum(sol.value(T(1:i))/nt);
end

obj_data = sol.value(obj);

% �O���̃v���b�g
figure(1);
plot(sol.value(S(:,1)),sol.value(S(:,2)),'k');hold on 
plot(sol.value(P(:,1)),sol.value(P(:,2)),['x','b']);hold on
plot(sol.value(Q(:,1)),sol.value(Q(:,2)),['x','r']);hold on

set(gca, 'FontSize', 12, 'LineWidth',2);

xlabel('X [mm]');
ylabel('Y [mm]');
legend('B-Spline curve','Control Points','Desired points','AutoUpdate','off');
axis equal;

set(gca, 'FontSize', 15, 'LineWidth',2);

%-- �O���̐����͈͂�`�� -------
plot_bound_square(Q,max_err);
%-------------------------

figure(2);
Vx = sol.value(DS(:,1)./T);
Vy = sol.value(DS(:,2)./T);
Ax = sol.value(DDS(:,1)./T.^2);
Ay = sol.value(DDS(:,2)./T.^2);
Jx = sol.value(DDDS(:,1)./T.^3);
Jy = sol.value(DDDS(:,2)./T.^3);
feed = sol.value(((DS(:,1)./T).^2+(sol.value(DS(:,2)./T)).^2).^(1/2));

S_data = sol.value(S);
P_data = sol.value(P);

plot(T_data,Vx);hold on
plot(T_data,Vy);hold on
yline([Vmin(1) Vmax(1)]);
legend('Vx','Vy','bound','AutoUpdate','off');
xlabel('Time [sec]');
ylabel('Velocity [mm/sec]');
set(gca, 'FontSize', 15, 'LineWidth',2);
ylim([Vmin(1)*1.1 Vmax(1)]*1.1);

figure(3);
plot(T_data,feed);
legend('Feed');
xlabel('Time [sec]');
ylabel('Feed [mm/sec]');
set(gca, 'FontSize', 15, 'LineWidth',2);


figure(4);
plot(T_data,Ax);hold on
plot(T_data,Ay);hold on 
yline([Amin(1) Amax(1)]);
legend('Ax','Ay','bound','AutoUpdate','off');
xlabel('Time [sec]');
ylabel('Accelerate [mm^2/sec^2]');
set(gca, 'FontSize', 15, 'LineWidth',2);
ylim([Amin(1)*1.1 Amax(1)]*1.1);

figure(5);
plot(T_data,Jx);hold on
plot(T_data,Jy);hold on 
yline([Jmin(1) Jmax(1)]);
legend('Jx','Jy','bound','AutoUpdate','off');
xlabel('Time [sec]');
ylabel('Jark [mm^3/sec^3]');
set(gca, 'FontSize', 15, 'LineWidth',2);
ylim([Jmin(1)*1.1 Jmax(1)]*1.1);

figure(6);
plot(T_data,T_opt);
legend('Optimal Time','AutoUpdate','off');
xlabel('Time [sec]');
ylabel('Optimal Discrete time [sec]');
set(gca, 'FontSize', 15, 'LineWidth',2);

figure(7);
plot(T_data,abs(Vx)./Vmax(1),'-.b');hold on

plot(T_data,abs(Vy)./Vmax(2),'b');hold on
plot(T_data,abs(Ax)./Amax(1),'m');hold on
plot(T_data,abs(Ay)./Amax(2),'-.m');hold on 
plot(T_data,abs(Jx)./Jmax(1),'g');hold on
plot(T_data,abs(Jy)./Jmax(2),'-.g');hold on
yline(1,'-.k');
legend('velocity(x)','velocity(y)','acceleration(x)','acceleration(y)',...
       'jark(x)','jark(y)','bound','AutoUpdate','off');
xlabel('Time [sec]');
ylabel('Normalization Otpimal Value');
set(gca, 'FontSize', 15, 'LineWidth',2);

TotalTime = sol.value(sum(T));
S_data = sol.value(sol.value(S));
DS_data = sol.value(sol.value(DS));
DDS_data = sol.value(sol.value(DDS));
DDDS_data = sol.value(sol.value(DDDS));

%-----------���̓f�[�^�̐���--------------
%-----------0.01�b���Ƃ̃f�[�^�ɂȂ�悤�ɐ��`�⊮���Ă܂�
Real_Vel = Calc_RealTime_Linear(T_data,dt,Vx,Vy);
Real_Pos = Calc_RealTime_Linear(T_data,dt,S_data(:,1),S_data(:,2));
Real_PosX = [Real_Pos(:,1),Real_Pos(:,2)];
Real_PosY = [Real_Pos(:,1),Real_Pos(:,3)];
S_len = TotalLength(sol.value(S));
ActualTime = S_len/mean(feed);
%-----------���삪���������̂ŃI�t-----------------------
% Repeat_num = 10;
% Real_Pos_repeat = Make_RealPosData(Real_Pos,dt,Repeat_num);
%-------------------------------------------------------
% save('real_Pos_Data.mat','Real_Pos_repeat');
save('1213_0.1[mm].mat','Real_PosX','Real_Vel','Real_PosY','T_data','T_opt','Q','max_err','S_data','DS_data','DDS_data','DDDS_data','P_data','Ax','Ay','Vx','Vy','Jx','Jy','feed','t','Amin','Amax','Vmin','Vmax','Jmin','Jmax','Real_Pos');