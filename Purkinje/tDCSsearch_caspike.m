% Simulate Purkinje cell calcium bursting activity under tDCS
% Generate the simulation results used in Fig.7
%
% (c) Xu (Shawn) Zhang, UConn
% xu.3.zhang@uconn.edu
% November 2021
%

clear;clc;

mkdir('recordings_caspike');
ampparam_all = -1.5:0.25:1.5;

for n = 1:length(ampparam_all)
    disp(n);
    ampparam = ampparam_all(n);
    
    formatSpec = '%.2f \n';
    
    opt_fileID = fopen('tDCSparams_caspike.txt','w');
    fprintf(opt_fileID,formatSpec,ampparam);
    fclose(opt_fileID);
    
    formatSpec = '%s \n';
    opt_fileID = fopen('trialname_caspike.txt','w');
    f_soma = strcat('recordings_caspike/soma','_',num2str(n),'.txt');
    fprintf(opt_fileID,formatSpec,f_soma);
    
    fclose(opt_fileID);
    [status,cmdout] = system('nrniv mosinit_tDCS_caspike.hoc');
end