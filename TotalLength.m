function var = TotalLength(S)   
    for i = 1:length(S)-1
        S_dif(i) = norm(S(i+1,:) - S(i,:));
    end
    var = sum(S_dif);
        
end
