%-----����------------------
%�f�[�^��̔񓙊Ԋu�̎��n��f�[�^�ɂ������܂œ��Ԋu�̎��Ԃ𑝉������Ă����Awhile�𔲂���
%�e���Ԋu�̎��ԂɕR�Â����f�[�^�ł͌��Ԃ�����̂�NaN��ۑ�����
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
%���U���� Real_Value(:,1)���Q�l�ɂ��Ĉ�莞�Ԃ��Ƃɑ��݂��Ȃ��f�[�^����`�⊮����
%���U�Ԋu�𒴍ׂ������Ă��f�[�^�_�Ԃ̗��U���Ԃ��߂��Ⴍ����L���̂ŁA���Ԋu�̎��Ԃɉ������l�ŕ⊮����K�v������B

end

