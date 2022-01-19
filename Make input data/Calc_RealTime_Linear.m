%-----説明------------------
%データ上の非等間隔の時系列データにおいつくまで等間隔の時間を増加させていき、whileを抜ける
%各等間隔の時間に紐づけたデータでは隙間があるのでNaNを保存する
%---------------------------
function Real_val =  Calc_RealTime_Linear(T_data,dt,Data_X,Data_Y)
t = 0:dt:T_data(end);
Data_i = 1;
for i = 1:length(t)
    sameflag = 1;
    while T_data(Data_i) < t(i)
        Data_i = Data_i+1;
        sameflag = 0;
    end
    
    if sameflag == 1
        Real_val(i,:) = [t(i),NaN,NaN];
    else
        Real_val(i,:) = [t(i),Data_X(Data_i),Data_Y(Data_i)];
    end
end

Real_val(1,:) = [0 Data_X(1) Data_Y(1)];
Real_val = fillmissing(Real_val,'linear','SamplePoint',Real_val(:,1));
%離散時間 Real_Value(:,1)を参考にして一定時間ごとに存在しないデータを線形補完する
%離散間隔を超細かくしてもデータ点間の離散時間がめちゃくちゃ広いので、一定間隔の時間に応じた値で補完する必要がある。

end

