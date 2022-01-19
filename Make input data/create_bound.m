function bound = create_bound(Q,max_err)
    dQ = diff(Q);
        bound.katamuki = dQ(:,2)./dQ(:,1);
        bound.housen   = -1*dQ(:,1)./dQ(:,2);
        bound.theta    = atan2(dQ(:,2),dQ(:,1));
        bound.dx       = max_err*cos(bound.theta);
        bound.dy       = max_err*sin(bound.theta);
        bound.housen_x = bound.dy;
        bound.housen_y = bound.dx;
        
     for i = 1:length(Q(:,1))
        bound.x(i,1) = bound.dx(i)+Q(i,1)
        bound.x(i,2) = bound.dx(i)+Q(i+1,1)
        bound.x(i,3) = -bound.dx(i)+Q(i,1)
        bound.x(i,4) = -bound.dx(i)+Q(i+1,1)

        bound.y(i,1) = bound.dy(i)+Q(i,2)
        bound.y(i,2) = bound.dy(i)+Q(i+1,2)
        bound.y(i,3) = -bound.dy(i)+Q(i,2)
        bound.y(i,4) = -bound.dy(i)+Q(i+1,2)
        
        %-------------ここから法線方向--------
        bound.x(i,5) = bound.housen_x(i)+Q(i,1)
        bound.x(i,6) = bound.housen_x(i)+Q(i+1,1)        
        bound.x(i,7) = -bound.housen_x(i)+Q(i,1)
        bound.x(i,8) = -bound.housen_x(i)+Q(i+1,1)
        
        bound.y(i,5) = -bound.housen_y(i)+Q(i,2)
        bound.y(i,6) = -bound.housen_y(i)+Q(i+1,2)
        bound.y(i,7) = bound.housen_y(i)+Q(i,2)
        bound.y(i,8) = bound.housen_y(i)+Q(i+1,2)
     end
     
     for i = length(Q)-1
         zahyou1(i,:) = (bound.dx(i)+Q(i,1),bound.dy(i)+Q(i,2));
         zahyou2(i,:) = 
         zahyou3(i,:) = [,bound.housen_y(i)+Q(i,2)]
         zahyou4(i,:) = [-bound.housen_x(i)+Q(i+1,1),bound.housen_y(i)+Q(i+1,2)]
     end
end