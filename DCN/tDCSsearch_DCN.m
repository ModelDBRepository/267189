% Simulate DCN rebound firing activities under tDCS
% Generate the simulation results used in Fig.4 (Panel A)
%
% (c) Xu (Shawn) Zhang, UConn
% xu.3.zhang@uconn.edu
% November 2021
%

clear;clc;
% Extended range of tDCS-induced field intensities
ampparam_all = -5:0.25:5;
mkdir('recordings_tDCS');

for n = 1:length(ampparam_all)
    disp(n);
    ampparam = ampparam_all(n);
    formatSpec = '%.2f \n';
    opt_fileID = fopen('tDCSparams.txt','w');
    fprintf(opt_fileID,formatSpec,ampparam);
    fclose(opt_fileID);
    
    formatSpec = '%s \n';
    opt_fileID = fopen('trialname_tDCS.txt','w');
    f_soma = strcat('recordings_tDCS/soma','_',num2str(n),'.txt');
    fprintf(opt_fileID,formatSpec,f_soma);
    fclose(opt_fileID);
    [status,cmdout] = system('nrniv mosinit_tDCS.hoc');
end