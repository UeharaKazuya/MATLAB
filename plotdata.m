close all
%%
dt = 0.01;
t = 0:dt:3-dt;
simulateS = [S(:,1) - 5, S(:,2)];

sgn_076(:,2) = -sgn_076(:,2);
sgn_076(:,6) = -sgn_076(:,6);


simulatePosition = zeros(length(realPosition(:,1)),2);
simulateVelocity = zeros(length(realPosition(:,1)),2);

gapP = 65;
for i=1:length(realPosition(:,1))-gapP
    simulatePosition(i,:) = realPosition(i+gapP,:);
end
for i=1:length(realPosition(:,1))-gapP
    simulateVelocity(i,:) = realVelocity(i+gapP,:).*[1, -1];
end

ex1 = figure;
s(1) = subplot(4,1,1); 
plot(sgn_076(:,1),sgn_076(:,2),'b-',simulateS(:,1),simulateS(:,2),'b--');
pbaspect([2 1 1]);
axis([-12 12 -1 11])

s(2) = subplot(4,1,2); 
plot(t,sgn_076(:,1),'b-',t,sgn_076(:,2),'r-',inputPosition(:,1),simulatePosition(:,1),'b--',inputPosition(:,1),simulatePosition(:,2),'r--');
s(3) = subplot(4,1,3); 
plot(t,sgn_076(:,5),'b-',t,sgn_076(:,6),'r-',inputPosition(:,1),simulateVelocity(:,1),'b--',inputPosition(:,1),-simulateVelocity(:,2),'r--');
s(4) = subplot(4,1,4); 
plot(t,sgn_076(:,3),'b-',t,sgn_076(:,4),'r-');


xlabel(s(2),'t(s)');
ylabel(s(2),'Position(mm)');
xlabel(s(3),'t(s)');
ylabel(s(3),'Velocity(m/s)');
xlabel(s(4),'t(s)');
ylabel(s(4),'input Volt(V)');

legend(s(1),'measured', 'simulation');
legend(s(2),'measured X-axis','measured Y-axis','simulation X-axis','simulation Y-axis');
legend(s(3),'measured X-axis','measured Y-axis','simulation X-axis','simulation Y-axis');
legend(s(4),'measured X-axis','measured Y-axis','simulation X-axis','simulation Y-axis');


text(s(1),-5, -3,'�c�[���p�X');
text(s(2),2, -9,'����ʒu');
text(s(3),2, -7.5,'���쑬�x');
text(s(4),2, -2.5,'���͓d��');
