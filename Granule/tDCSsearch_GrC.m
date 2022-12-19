% Simulate granule cell activities under tDCS
% Generate the simulation results used in Fig.4 (Panel C)
%
% (c) Xu (Shawn) Zhang, UConn
% xu.3.zhang@uconn.edu
% November 2021
%

clear;clc;
frequency1_all = [12.5 16.6 25 50 100 200 10 1000/120 1000/140];
ampparam_all = -1.5:0.25:1.5; % -1.5:0.25:1.5;
mkdir('recordings_synapse_189-1-33dw');

y_all = [];
for k = 1:length(frequency1_all)
    for l = 1:length(ampparam_all) % -3
        x = [frequency1_all(k);ampparam_all(l)];
        y = [k,l];
        y_all = [y_all;y];
    end
end

for n = 1:size(y_all,1)
    disp(n);
    y = y_all(n,:);
    frequency1 = frequency1_all(y(1));
    ampparam = ampparam_all(y(2));
    
    formatSpec = '%.8f \n';
    
    opt_fileID = fopen('tDCSparams_synapse_189-1-33dw.txt','w');
    fprintf(opt_fileID,formatSpec,frequency1);
    fprintf(opt_fileID,formatSpec,ampparam);
    fclose(opt_fileID);
    
    disp(frequency1);
    disp(ampparam);
    
    formatSpec = '%s \n';
    opt_fileID = fopen('trialname_synapse_189-1-33dw.txt','w');
    f_soma = strcat('recordings_synapse_189-1-33dw/soma','_',num2str(n),'.txt');
    fprintf(opt_fileID,formatSpec,f_soma);
    fclose(opt_fileID);
    [status,cmdout] = system('nrniv mosinit_tDCS_synapse_189-1-33dw.hoc');
end