function [Real,ActualTime] = make_input_data(inputArg1,inputArg2)
%UNTITLED2 ���̊֐��̊T�v�������ɋL�q
%   �ڍא����������ɋL�q
Real.Vel = Calc_RealTime_Linear(T_data,dt,Vx,Vy);
Real.Pos = Calc_RealTime_Linear(T_data,dt,S_data(:,1),S_data(:,2));
Real.PosX = [Real.Pos(:,1),Real.Pos(:,2)];
Real.PosY = [Real.Pos(:,1),Real.Pos(:,3)];
S_len = TotalLength(sol.value(S));
ActualTime = S_len/mean(feed);
end

