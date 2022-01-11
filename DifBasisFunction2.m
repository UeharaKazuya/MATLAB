%% Calculate Differential of Basis Function ver.2
% u : Knot Vector
% j : j-th Control Ponit
% k : k-th Basis Function <-- n-th B-Spline
% t : Time
function var = DifBasisFunction2(u,j,k,t)   
    w1 = 0.0;
    w2 = 0.0;
        
    if k == 0 
        if u(j) < t && t <= u(j+1)
            var = 1.0;
        else
            var = 0.0;
        end
    else
        if (u(j+k+1)-u(j+1)) ~= 0  
            a(j) = (k-1-j)*(a(i,j-1)-a(i-1,j-1))/(u(j+k+1-j)-u(j+1)); 
        end
        var = a(j)*BasicFunction(u,j);
    end  
end

function var = DifcalculateA(u,j,k,t,i,Q)
    w1 = 0.0;
    w2 = 0.0;
    
    if i == 0
        var = Q;
    else
        if (u(j+k+1-i)-u(j)) ~= 0  
            a(j) = (k-1-j)*(a(i,j-1)-a(i-1,j-1))/(u(j+k+1-i)-u(j)); 
        end
    end
end