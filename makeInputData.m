function Real = makeInputData(T_data,dt,V(:,2),V(:,3),tLength)
%makeInputData 入力値を作成
%   

calPosition = zeros(tLength/dt,2);

for t = 0:dt:tLength
    calPosition(t,:) = calPosition + V(i,:).*dt;
    
end

end

