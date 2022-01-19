%-------------入力------------
%  max_err：許容誤差
%　Q：目標座標
%  k：B-Splineの次数
%  n_sampling：１つのセグメントをいくつの離散点で構成するか
%　VmaxからJmin：速度，加速度，ジャークの最大値，最小値
%  dt：入力データを作る際の離散時間
%-----------------------------


%-------------出力------------
%　Real_Pos_data：入力データ：0.01秒（dt秒）ごとに入力データが得られるように成形したもの
%　Real_Pos_repeat：上のデータを繰り返したもの．元のプログラムがおかしくて今はできてないです　すみません
%  figure(1)：最適経路
%  figure(2)：最適速度
%  figure(3)：最適送り速度
%  figure(4)：最適加速度
%  figure(5)：最適ジャーク
%  figure(6)：最適離散時間
%  figure(7)：それぞれを正規化して制約条件の範囲に
% 　　　　　　入っているか一目で確認するためのグラフ
%-----------------------------


%---------関数の説明-----------------------------------------------------------
%  loadlib：必要なライブラリを読み込むためのもの（各自のフォルダを指定）
%  Knot：ノットベクトルの計算

%  WichSpan：B-Splineのスパンを計算して基底関数の計算に必要なパラメータを求める
%  Calc_BasisFunc：B-Spline基底関数の計算
%  DersBasisFuns：基底関数を微分するもの

%  create_bound：figure(1)の生成範囲をプロットするために必要なデータを生成（大変雑に作成したので見づらい）
%  Calc_RealTime_Linear：入力データの生成　ばらばらの離散時間で生成されたデータを線形補完して等間隔の離散時間で表したもの
%  Make_RealPosData：入力データを繰り返させたかったもの（今は動いてない，Real_Pos_dataを繰り返し配列に格納するだけなので大した事は書いてない）
%  ToTalLength：軌道Sの長さを計算するもの
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
dt = 0.01;%0.01[sec] 入力データとして離散時間dtごとに線形補完するときに利用

%---最適化するため に変化させる値の上下限設定---
Vmax = [1, 1];%x,y [mm/sec]
Vmin = -Vmax;
Amax = [10,10]; %[mm/s^2]
Amin = -Amax;
Jmax = [100, 100]; %[mm/s^3]
Jmin = -Jmax;



%------最適化変数P の定義---------
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
u = Knot(nKnot,k,nQ);  %開一様ノットベクトル作成


%%  Calculate B-spline

%-----------各離散時間での値の場合のB-Spline--------------
bMatrix_risan = zeros(nt,nQ); % 各制御点における基底関数の値
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

% 各制御点の座標におけるB-SplineがS、微分DS、2階微分DDS，３階微分DDDS
S = bMatrix_risan*P;
DS = DbMatrix_risan*P;
DDS = DDbMatrix_risan*P;
DDDS = DDDbMatrix_risan*P;

%% 曲率
for i = 1: nt
    for j =1:nQ
        dif_data = [DS(i, 1), DS(i, 2);
        DDS(i, 1), DDS(i, 2)];%xとyの微分と2階微分
        R(i) = {(DS(i,1)^2+DS(i,2)^2)^(3/2) / det(dif_data)};
    end
end
%% -------------各サンプル点間の時間最小化----------------------
% T_optはそれぞれdTを求めて一セグメント分すべて足し合わせることで各動作時間Tを最小化するという流れになる

T = opti.variable(nt);% 最適化変数の設定
%opti.set_initial(T,zeros(1,nt));

for i = 1:length(Q)
    opti.set_initial(x(i*3-2),Q(i,1));
    opti.set_initial(y(i*3-2),Q(i,2));
    opti.set_initial(x(i*3-1),Q(i,1));
    opti.set_initial(y(i*3-1),Q(i,2));
    opti.set_initial(x(i*3),Q(i,1));
    opti.set_initial(y(i*3),Q(i,2));
end
%----- 目的関数の設定 ------------- 
obj = sum(T);% 別にopti.minimize(sum(T));でもいいけど結果をプロットするとき目的関数を呼び出せないから不便
opti.minimize(obj);


%始点と終点で停止するという条件
for i = 1:nt
    opti.subject_to(Vmin(1)*T(i) <= DS(i,1));
    opti.subject_to(Vmin(2)*T(i) <= DS(i,2)); %B-SPlineには時間の概念が入っていないので、制約条件にVmax,Vminを組み込む際、無次元化して取り込む必要がある。
    opti.subject_to(Vmax(1)*T(i) >= DS(i,1)); %そのため、Vmin[mm/s]*T[s] = V[mm/τ]と無次元化した速度パラメータにしている 
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
% ------スタートと終わりの点を通るように制約
opti.subject_to({x(1)==Q(1,1),y(1)==Q(1,2)});
opti.subject_to({x(end)==Q(end,1),y(end)==Q(end,2)});
% ------ 円の範囲内に制約 ----------------
for i = 1:length(Q)
    opti.subject_to(max_err^2 >= ((x(i*3-2)-Q(i,1)).^2 + (y(i*3-2)-Q(i,2)).^2))
    opti.subject_to(max_err^2 >= ((x(i*3-1)-Q(i,1)).^2 + (y(i*3-1)-Q(i,2)).^2))
    opti.subject_to(max_err^2 >= ((x(i*3)-Q(i,1)).^2 + (y(i*3)-Q(i,2)).^2))
end
% -------------- 最終セグメントで停止するという条件 ----------
opti.subject_to(x(1)==x(2));
opti.subject_to(y(1)==y(2));
opti.subject_to(x(end-1)==x(end));
opti.subject_to(y(end-1)==y(end));

%% ---------------これまでに定義した条件を用いて最適化問題を解く部分 ---------

%---ソルバーのオプション設定 --------
p_opts = struct('expand',true);
s_opts = struct('max_iter',10000);
opti.solver('ipopt',p_opts,s_opts);
sol = opti.solve();

% 最適化した離散時間の格納
T_opt = sol.value(T);

%% ------plot result---------
%T_dataは各離散時間Tの通り変化したときの時間を表す
%ntで割っているのはT*Vmin<=DS<=T*Vmaxという式に関係する。DSは計算上では{S(i+1)-S(i)}/(1/nt)である。これは最大時間が１という正規化された時間軸で表されるためである。
%そのため、DSを求めるためにサンプル数ntで全体時間１を分割した時間(1/nt)間隔で微分しているとわかる。
%最適化で求めたTという値は正規化された各離散時間(1/nt)をTという値に引き延ばすというものである。

T_opt = T_opt/nt;
for i = 1:length(sol.value(T))
    T_data(i) = sum(sol.value(T(1:i))/nt);
end

obj_data = sol.value(obj);

% 軌道のプロット
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

%-- 軌道の生成範囲を描画 -------
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

%-----------入力データの生成--------------
%-----------0.01秒ごとのデータになるように線形補完してます
Real_Vel = Calc_RealTime_Linear(T_data,dt,Vx,Vy);
Real_Pos = Calc_RealTime_Linear(T_data,dt,S_data(:,1),S_data(:,2));
Real_PosX = [Real_Pos(:,1),Real_Pos(:,2)];
Real_PosY = [Real_Pos(:,1),Real_Pos(:,3)];
S_len = TotalLength(sol.value(S));
ActualTime = S_len/mean(feed);
%-----------動作がおかしいのでオフ-----------------------
% Repeat_num = 10;
% Real_Pos_repeat = Make_RealPosData(Real_Pos,dt,Repeat_num);
%-------------------------------------------------------
% save('real_Pos_Data.mat','Real_Pos_repeat');
save('1213_0.1[mm].mat','Real_PosX','Real_Vel','Real_PosY','T_data','T_opt','Q','max_err','S_data','DS_data','DDS_data','DDDS_data','P_data','Ax','Ay','Vx','Vy','Jx','Jy','feed','t','Amin','Amax','Vmin','Vmax','Jmin','Jmax','Real_Pos');