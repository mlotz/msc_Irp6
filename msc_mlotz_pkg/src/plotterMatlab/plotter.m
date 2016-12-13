clear all;
close all;

filename = '/home/mlotz/msc_ws_irp6/logs/reports.dat';
delimiterIn = ' ';
headerlinesIn = 1;
A = importdata(filename,delimiterIn,headerlinesIn);

t = A.data(:,1);
X = A.data(:,2);
Y = A.data(:,3);

f1 = figure(1);
hold on;
title('Trajektoria XY');
xlabel('X');
ylabel('Y');
plot(X,Y);
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
