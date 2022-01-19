%何回も繰り返し動作するようなデータを作る


%----- 入力 ---------
%Real_Pos：CalC_RealTime_Linerで計算した
%dt：離散時間
%Repeat_num：繰り返し回数
%--------------------


%----- 出力 ---------
%Real_Pos_repeat：repeatnumの回数だけ繰り返した入力データ
%--------------------


function Real_Pos_repeat = Make_RealPosData(Real_Pos,dt,Repeat_num)

Real_Pos__ = zeros(5*(1/dt),2);%最初の５秒間停止
Real_Pos__(5*(1/dt)+1:(5*(1/dt)+1)+length(Real_Pos)-1 , 1:3) = Real_Pos;%目標軌道を代入
T_len = length(Real_Pos__);
for j = 1:Repeat_num
    Real_Pos_repeat(T_len*(j-1)+1:T_len*(j-1)+length(Real_Pos__),1:3) = Real_Pos__;
end
Real_Pos_repeat = Real_Pos__;

for i = 1:500
    Real_Pos_repeat(length(Real_Pos__)-1+i,2:3) = [Real_Pos__(end,2),Real_Pos__(end,3)];
end

T = 0:dt:(length(Real_Pos_repeat)-1)*dt;
Real_Pos_repeat(:,1)  = T;

end