%% Calculate Knot Vector Function
% u : Knot Vector
% m : Number of Knots in Knot Vector
% n : Degree of B-Spline
function u = OpenUniformKnotVector(m,n,nQ)
    u = zeros(1,m);
    for i = 1:1:m
          if i < n+2 
              u(i) = 0;
          elseif i > m - (n + 1) 
%               u(i) = m - 1 - 2 * n;
              u(i) = nQ-1;
          else
%               u(i) = i - n - 1;
              u(i) = i-n -2 +(n+1)/2;
          end
    end
    u = u/u(end);
%     u = u * (nQ-1);
end
