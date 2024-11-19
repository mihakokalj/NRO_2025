% NALOGA 1
naloga1 = 'naloga1_1.txt';

data = importdata(naloga1);

t = data.data;

%disp(t);

% NALOGA 2.1

naloga2 = 'naloga1_2.txt';
fileID = fopen(naloga2, 'r');

firstLine = fgetl(fileID);
numValues = sscanf(firstLine, 'stevilo_podatkov_P: %d'); 

P = zeros(numValues, 1);

for i = 1:numValues
    P(i) = fscanf(fileID, '%f', 1);
end

fclose(fileID);

%disp('Vsebina vektorja P:');
%disp(P);

% NALOGA 2.2

figure;
plot(t, P, 'k.', 'LineWidth', 1);
xlabel('t [s]'); 
ylabel('P [W]');
title('Graf P(t)'); 
grid on; 

% NALOGA 3

vrednost_integrala = 0;

dt = t(2) - t(1);

for i = 1:length(P)-1
    vrednost_integrala = vrednost_integrala + (P(i) + P(i+1)) * dt / 2;
end
disp('Vrednost integrala:')
disp(vrednost_integrala);

integral_trapz = trapz(t, P);

disp('Vrednost integrala z metodo TRAPZ:')
disp(integral_trapz)


