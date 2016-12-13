clear all;
close all;

filename = '/home/mlotz/msc_ws_irp6/logs/reports.dat';
delimiterIn = ' ';
headerlinesIn = 1;
A = importdata(filename,delimiterIn,headerlinesIn);

xFN = A.data(:,1);
yFN= A.data(:,2);
zFN = A.data(:,3);
t = str2double(A.textdata(2:end,1));
X = str2double(A.textdata(2:end,2));
Y = str2double(A.textdata(2:end,3));
xF = str2double(A.textdata(2:end,17));
yF = str2double(A.textdata(2:end,18));
zF = str2double(A.textdata(2:end,19));


% f1 = figure(1);
% hold on;
% title('Trajektoria XY');
% xlabel('X');
% ylabel('Y');
% plot(X,Y);
% f2 = figure(2);
% hold on;
% title('X w czasie');
% xlabel('t');
% ylabel('X');
% plot(t,X);
% f3 = figure(3);
% hold on;
% title('Y w czasie');
% xlabel('t');
% ylabel('Y');
% plot(t,Y);

f4 = figure(4);
hold on;
title('optForce2 - xFN');
xlabel('t');
ylabel('xFN');
plot(t,xFN);

f5 = figure(5);
hold on;
title('optForce2 - yFN');
xlabel('t');
ylabel('yFN');
plot(t,yFN);

f6 = figure(6);
hold on;
title('optForce2 - zFN');
xlabel('t');
ylabel('zFN');
plot(t,zFN);


