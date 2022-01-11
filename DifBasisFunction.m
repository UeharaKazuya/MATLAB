%% Calculate Differential of Basis Function
% u : Knot Vector
% j : j-th Control Ponit
% k : k-th Basis Function <-- n-th B-Spline
% t : Time
function var = DifBasisFunction(i,u,j,k,t)   
    w1 = 0.0;
    w2 = 0.0;
    
%     if k == 0 
%         if u(j) < t && t <= u(j+1)
%             var = 1.0;
%         else
%             var = 0.0;
%         end
%     else
    if i == 1
        if (u(j+k+1)-u(j+1)) ~= 0  
            w1 = k * BasisFunction(u,j+1,k-1,t) / (u(j+k+1)-u(j+1));
        end
        if (u(j+k)-u(j)) ~= 0  
            w2 = k * BasisFunction(u,j,k-1,t) / (u(j+k) - u(j));
        end
        var = -w1 + w2;
        
    elseif i >= 2
        if (u(j+k+1)-u(j+1)) ~= 0  
            w1 = k * DifBasisFunction(i-1,u,j+1,k-1,t) / (u(j+k+1)-u(j+1));
        end
        if (u(j+k)-u(j)) ~= 0  
            w2 = k * DifBasisFunction(i-1,u,j,k-1,t) / (u(j+k) - u(j));
        end
        var = -w1 + w2;
        
    else
        fprintf('error.\n');
    end
%     end
end  

