% Simulate Purkinje cell activities under climbing fiber synaptic inputs and tDCS
% Generate the simulation results used in Fig.6 (Panel C)
%
% (c) Xu (Shawn) Zhang, UConn
% xu.3.zhang@uconn.edu
% November 2021
%

clear;clc;

mkdir('recordings_1cs');
ampparam_all = -1.5:0.25:1.5;

for n = 1:length(ampparam_all)
    disp(n);
    ampparam = ampparam_all(n);
    
    formatSpec = '%.2f \n';
    
    opt_fileID = fopen('tDCSparams_1cs.txt','w');
    fprintf(opt_fileID,formatSpec,ampparam);
    fclose(opt_fileID);
    
    formatSpec = '%s \n';
    opt_fileID = fopen('trialname_1cs.txt','w');
    f_soma = strcat('recordings_1cs/soma','_',num2str(n),'.txt');
    fprintf(opt_fileID,formatSpec,f_soma);
    fclose(opt_fileID);
    [status,cmdout] = system('nrniv mosinit_tDCS_1cs.hoc');
end