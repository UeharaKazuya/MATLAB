function plot_bound_square(Q,max_err)
dQ = diff(Q);
theta = atan2(dQ(:,2),dQ(:,1));

x = max_err;
y = max_err;

for i = 1:length(Q)-1
    theta_data(i,:) = [0+theta(i):pi/2:2*pi+theta(i)];
    
    X_start(i,:) = cos(theta_data(i,:))*x-sin(theta_data(i,:))*y+Q(i,1);
    Y_start(i,:) = sin(theta_data(i,:))*y+cos(theta_data(i,:))*y+Q(i,2);
    X_end(i,:) = cos(theta_data(i,:))*x-sin(theta_data(i,:))*y+Q(i+1,1);
    Y_end(i,:) = sin(theta_data(i,:))*y+cos(theta_data(i,:))*y+Q(i+1,2);
    
    plot(Q(:,1),Q(:,2),'r:+');hold on
    plot(X_start(i,:),Y_start(i,:),'b');hold on 
    plot(X_end(i,:),Y_end(i,:),'b');hold on 
%   方向チェック用
%     plot(X_start(i,2),Y_start(i,2),'b:x');hold on 
%     plot(X_end(i,1),Y_end(i,1),'b:x');hold on 
    
    plot([X_start(i,2),X_end(i,1)],[Y_start(i,2),Y_end(i,1)],'b');hold on
    plot([X_start(i,3),X_end(i,4)],[Y_start(i,3),Y_end(i,4)],'b');
    

end
for i = 1:length(Q)
    t = 0:0.01:2*pi;
    cx = Q(i,1); cy = Q(i,2); % 中心
    r = max_err;           % 半径
    plot(r*sin(t)+cx,r*cos(t)+cy,'r');hold on
end

end