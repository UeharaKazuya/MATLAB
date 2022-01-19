
function u = Knot(m,n,nP) %ノットの数:m、スプラインの次数：n、nP：制御点の数
    u = zeros(1,m);
    for i = 1:m
          if i < n+2 
              u(i) = 0;
          elseif i > m - (n + 1) 
%               u(i) = m - 1 - 2 * n;
              u(i) = nP-1;
          else
%               u(i) = i - n - 1;
              u(i) = i-n -2 +(n+1)/2;
          end
    end
    u = u/u(end);%大きさを１にするために正規化している
%     u = u * (nQ-1);
end