% Simulate Purkinje cell activities under climbing fiber synaptic inputs
% and voltage shifts applied to soma or dendritic compartments
% Generate the simulation results used in Fig.7
%
% (c) Xu (Shawn) Zhang, UConn
% xu.3.zhang@uconn.edu
% November 2021
%

clear;clc;

load('dvall.mat');
vshift_all = -1.5:0.25:1.5;

%% Somatic voltage shifts
mkdir('recordings_calcium_soma_vshift');
for n = 1:length(vshift_all)
    disp(n);
    vshift = vshift_all(n);
    
    tmpdv = dv_all*vshift; % Voltage shifts for all compartments
    
    formatSpec = '%.4f \n';
    opt_fileID = fopen('Vshifts_calcium_soma_vshift.txt','w');
    fprintf(opt_fileID,formatSpec,tmpdv);
    fclose(opt_fileID);
    
    formatSpec = '%s \n';
    opt_fileID = fopen('trialname_calcium_soma_vshift.txt','w');
    f_soma = strcat('recordings_calcium_soma_vshift/soma','_',num2str(n),'.txt');
    fprintf(opt_fileID,formatSpec,f_soma);
    fclose(opt_fileID);
    
    [status,cmdout] = system('nrniv mosinit_calcium_soma_vshift.hoc');
end

%% Dendritic voltage shifts
mkdir('recordings_calcium_dend_vshift');
for n = 1:length(vshift_all)
    disp(n);
    vshift = vshift_all(n);
    
    tmpdv = dv_all*vshift; % Voltage shifts for all compartments
    
    formatSpec = '%.4f \n';
    opt_fileID = fopen('Vshifts_calcium_dend_vshift.txt','w');
    fprintf(opt_fileID,formatSpec,tmpdv);
    fclose(opt_fileID);
    
    formatSpec = '%s \n';
    opt_fileID = fopen('trialname_calcium_dend_vshift.txt','w');
    f_soma = strcat('recordings_calcium_dend_vshift/soma','_',num2str(n),'.txt');
    fprintf(opt_fileID,formatSpec,f_soma);
    fclose(opt_fileID);
    
    [status,cmdout] = system('nrniv mosinit_calcium_dend_vshift.hoc');
end
