% Simulate Purkinje cell activities under mossy fiber synaptic inputs and tDCS
% Generate the simulation results used in Fig.5
%
% (c) Xu (Shawn) Zhang, UConn
% xu.3.zhang@uconn.edu
% November 2021
%

clear;clc;

rng(1027);

load('dend_train/dend_data.mat')
mkdir('recordings_dend_train_delayedonset');

ampparam_all = -1.5:0.75:1.5;
synparam_all = 8:0.5:12;
y_all = [];
for k = 1:length(ampparam_all)
    for l = 1:length(synparam_all) % -3
        x = [ampparam_all(k);synparam_all(l)];
        y = [k,l];
        y_all = [y_all;y];
    end
end

numdend_exc = 1000;
numdend_inh = 100;
numdend_all = numdend_exc + numdend_inh;
dendnum_all = sum(dendnum);
dendnum_cum = cumsum(dendnum);

dend_rand = randperm(dendnum_all);
dend_rand = sort(dend_rand(1:numdend_all));

dendname_all = cell(numdend_all,1);

dend_inh_ind = sort(randi(numdend_all,1,10));
dend_inh_rand = dend_rand(dend_inh_ind);

formatSpec = '%s \n';
dendname_fileID = fopen('dend_train/dendnames_delayedonset.txt','w');

for i = 1:numdend_all
    if ismember(i,dend_inh_ind)
        continue;
    else
        tmpdendrand = dend_rand(i);
        tmpdendbr = sum(tmpdendrand>dendnum_cum) + 1;
        if tmpdendbr<=1
            tmpdendnum = tmpdendrand - 1;
        else
            tmpdendnum = tmpdendrand-dendnum_cum(tmpdendbr-1) - 1;
        end
        tmpdend_all = strcat(dendbrname{tmpdendbr},'[',num2str(tmpdendnum),']');
        fprintf(dendname_fileID,formatSpec,tmpdend_all);
    end
end
fclose(dendname_fileID);

formatSpec = '%s \n';
dendname_inh_fileID = fopen('dend_train/dendnames_inh_delayedonset.txt','w');
for i = 1:length(dend_inh_ind)
    tmpdendrand = dend_inh_rand(i);
    tmpdendbr = sum(tmpdendrand>dendnum_cum) + 1;
    if tmpdendbr<=1
        tmpdendnum = tmpdendrand - 1;
    else
        tmpdendnum = tmpdendrand-dendnum_cum(tmpdendbr-1) - 1;
    end
    tmpdend_all = strcat(dendbrname{tmpdendbr},'[',num2str(tmpdendnum),']');
    fprintf(dendname_inh_fileID,formatSpec,tmpdend_all);
end
fclose(dendname_inh_fileID);

[status,cmdout] = system('nrniv mosinit_tDCS_dend_train_delayedonset_prepare.hoc');

for n = 1:size(y_all,1)
    disp(n);
    y = y_all(n,:);
    ampparam = ampparam_all(y(1));
    synparam = synparam_all(y(2));
    
    formatSpec = '%.8f \n';
    
    opt_fileID = fopen('tDCSparams_dend_train_delayedonset.txt','w');
    fprintf(opt_fileID,formatSpec,ampparam);
    fprintf(opt_fileID,formatSpec,synparam);
    fclose(opt_fileID);
    
    formatSpec = '%s \n';
    opt_fileID = fopen('trialname_dend_train_delayedonset.txt','w');
    f_soma = strcat('recordings_dend_train_delayedonset/soma','_',num2str(n),'.txt');
    f_dend_event = strcat('recordings_dend_train_delayedonset/dend_event','_',num2str(n),'.txt');
        
    fprintf(opt_fileID,formatSpec,f_soma);
    fprintf(opt_fileID,formatSpec,f_dend_event);
    
    fclose(opt_fileID);
    [status,cmdout] = system('nrniv mosinit_tDCS_dend_train_delayedonset.hoc');
end