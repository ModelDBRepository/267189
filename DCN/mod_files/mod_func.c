#include <stdio.h>
#include "hocdec.h"
#define IMPORT extern __declspec(dllimport)
IMPORT int nrnmpi_myid, nrn_nobanner_;

extern void _CaConc_reg();
extern void _CaHVA_reg();
extern void _CaLVA_reg();
extern void _CalConc_reg();
extern void _DCNsyn_reg();
extern void _DCNsynGABA_reg();
extern void _DCNsynNMDA_reg();
extern void _GammaStim_reg();
extern void _NaF_reg();
extern void _NaP_reg();
extern void _SK_reg();
extern void _TNC_reg();
extern void _fKdr_reg();
extern void _fzap_reg();
extern void _fzap_DC_reg();
extern void _h_reg();
extern void _lenconst_reg();
extern void _noisyexp2syn_reg();
extern void _pasDCN_reg();
extern void _sKdr_reg();
extern void _xtrau_reg();

void modl_reg(){
	//nrn_mswindll_stdio(stdin, stdout, stderr);
    if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
	fprintf(stderr, "Additional mechanisms from files\n");

fprintf(stderr," CaConc.mod");
fprintf(stderr," CaHVA.mod");
fprintf(stderr," CaLVA.mod");
fprintf(stderr," CalConc.mod");
fprintf(stderr," DCNsyn.mod");
fprintf(stderr," DCNsynGABA.mod");
fprintf(stderr," DCNsynNMDA.mod");
fprintf(stderr," GammaStim.mod");
fprintf(stderr," NaF.mod");
fprintf(stderr," NaP.mod");
fprintf(stderr," SK.mod");
fprintf(stderr," TNC.mod");
fprintf(stderr," fKdr.mod");
fprintf(stderr," fzap.mod");
fprintf(stderr," fzap_DC.mod");
fprintf(stderr," h.mod");
fprintf(stderr," lenconst.mod");
fprintf(stderr," noisyexp2syn.mod");
fprintf(stderr," pasDCN.mod");
fprintf(stderr," sKdr.mod");
fprintf(stderr," xtrau.mod");
fprintf(stderr, "\n");
    }
_CaConc_reg();
_CaHVA_reg();
_CaLVA_reg();
_CalConc_reg();
_DCNsyn_reg();
_DCNsynGABA_reg();
_DCNsynNMDA_reg();
_GammaStim_reg();
_NaF_reg();
_NaP_reg();
_SK_reg();
_TNC_reg();
_fKdr_reg();
_fzap_reg();
_fzap_DC_reg();
_h_reg();
_lenconst_reg();
_noisyexp2syn_reg();
_pasDCN_reg();
_sKdr_reg();
_xtrau_reg();
}
