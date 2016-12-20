clear all;
close all;

filename = '/home/mlotz/msc_ws_irp6/logs/reports.dat';
plotPath = '/home/mlotz/msc_ws_irp6/plots/';
delimiterIn = ' ';
headerlinesIn = 1;
A = importdata(filename,delimiterIn,headerlinesIn);

xFN1 = A.data(:,1);
yFN1= A.data(:,2);
zFN1 = A.data(:,3);
t = str2double(A.textdata(2:end,1));
X = str2double(A.textdata(2:end,2));
Y = str2double(A.textdata(2:end,3));
% xF = str2double(A.textdata(2:end,17));
% yF = str2double(A.textdata(2:end,18));
% zF = str2double(A.textdata(2:end,19));


% f1 = figure(1);
% hold on;
% title('Trajektoria XY');
% xlabel('X');
% ylabel('Y');
% plot(X,Y);
f2 = figure(2);
hold on;
title('X w czasie');
xlabel('t');
ylabel('X');
plot(t,X);
f3 = figure(3);
hold on;
title('Y w czasie');
xlabel('t');
ylabel('Y');
plot(t,Y);

%asd


f4 = figure(4);
hold on;
title('optForce2 - xFN1');
xlabel('t');
ylabel('xFN1');
plot(t,xFN1);

f5 = figure(5);
hold on;
title('optForce2 - yFN1');
xlabel('t');
ylabel('yFN1');
plot(t,yFN1);

f6 = figure(6);
hold on;
title('optForce2 - zFN1');
xlabel('t');
ylabel('zFN1');
plot(t,zFN1);

saveas(f2,strcat(plotPath,'X.pdf'))
saveas(f3,strcat(plotPath,'Y.pdf'))
saveas(f4,strcat(plotPath,'xFN1.pdf'))
saveas(f5,strcat(plotPath,'yFN1.pdf'))
saveas(f6,strcat(plotPath,'zFN1.pdf'))

close all;


