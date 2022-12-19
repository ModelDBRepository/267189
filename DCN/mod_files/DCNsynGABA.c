/* Created by Language version: 7.7.0 */
/* VECTORIZED */
#define NRN_VECTORIZED 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib_ansi.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define nrn_init _nrn_init__DCNsynGABA
#define _nrn_initial _nrn_initial__DCNsynGABA
#define nrn_cur _nrn_cur__DCNsynGABA
#define _nrn_current _nrn_current__DCNsynGABA
#define nrn_jacob _nrn_jacob__DCNsynGABA
#define nrn_state _nrn_state__DCNsynGABA
#define _net_receive _net_receive__DCNsynGABA 
#define state state__DCNsynGABA 
 
#define _threadargscomma_ _p, _ppvar, _thread, _nt,
#define _threadargsprotocomma_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt,
#define _threadargs_ _p, _ppvar, _thread, _nt
#define _threadargsproto_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 /* Thread safe. No static _p or _ppvar. */
 
#define t _nt->_t
#define dt _nt->_dt
#define tauRise _p[0]
#define tauFall _p[1]
#define e _p[2]
#define startDeprLevel _p[3]
#define deprLevel _p[4]
#define i _p[5]
#define g _p[6]
#define A _p[7]
#define B _p[8]
#define relProbSS _p[9]
#define relProb (_p + 10)
#define freq _p[12]
#define tau _p[13]
#define tSpikes (_p + 14)
#define ISI _p[16]
#define notFirstSpike _p[17]
#define factor _p[18]
#define DA _p[19]
#define DB _p[20]
#define v _p[21]
#define _g _p[22]
#define _tsav _p[23]
#define _nd_area  *_ppvar[0]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  -1;
 static Datum* _extcall_thread;
 static Prop* _extcall_prop;
 /* external NEURON variables */
 /* declaration of user functions */
 static double _hoc_giveFractionG();
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 
#define NMODL_TEXT 1
#if NMODL_TEXT
static const char* nmodl_file_text;
static const char* nmodl_filename;
extern void hoc_reg_nmodl_text(int, const char*);
extern void hoc_reg_nmodl_filename(int, const char*);
#endif

 extern Prop* nrn_point_prop_;
 static int _pointtype;
 static void* _hoc_create_pnt(_ho) Object* _ho; { void* create_point_process();
 return create_point_process(_pointtype, _ho);
}
 static void _hoc_destroy_pnt();
 static double _hoc_loc_pnt(_vptr) void* _vptr; {double loc_point_process();
 return loc_point_process(_pointtype, _vptr);
}
 static double _hoc_has_loc(_vptr) void* _vptr; {double has_loc_point();
 return has_loc_point(_vptr);
}
 static double _hoc_get_loc_pnt(_vptr)void* _vptr; {
 double get_loc_point_process(); return (get_loc_point_process(_vptr));
}
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _extcall_prop = _prop;
 }
 static void _hoc_setdata(void* _vptr) { Prop* _prop;
 _prop = ((Point_process*)_vptr)->_prop;
   _setdata(_prop);
 }
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 0,0
};
 static Member_func _member_func[] = {
 "loc", _hoc_loc_pnt,
 "has_loc", _hoc_has_loc,
 "get_loc", _hoc_get_loc_pnt,
 "giveFractionG", _hoc_giveFractionG,
 0, 0
};
#define giveFractionG giveFractionG_DCNsynGABA
 extern double giveFractionG( _threadargsproto_ );
 /* declare global and static user variables */
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "tauRise", "ms",
 "tauFall", "ms",
 "e", "mV",
 "A", "microsiemens",
 "B", "microsiemens",
 "deprLevel", "1",
 "i", "nA",
 "g", "microsiemens",
 0,0
};
 static double A0 = 0;
 static double B0 = 0;
 static double delta_t = 0.01;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(_NrnThread*, _Memb_list*, int);
static void nrn_state(_NrnThread*, _Memb_list*, int);
 static void nrn_cur(_NrnThread*, _Memb_list*, int);
static void  nrn_jacob(_NrnThread*, _Memb_list*, int);
 static void _hoc_destroy_pnt(_vptr) void* _vptr; {
   destroy_point_process(_vptr);
}
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(_NrnThread*, _Memb_list*, int);
static void _ode_matsol(_NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[2]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"DCNsynGABA",
 "tauRise",
 "tauFall",
 "e",
 "startDeprLevel",
 0,
 "deprLevel",
 "i",
 "g",
 0,
 "A",
 "B",
 0,
 0};
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
  if (nrn_point_prop_) {
	_prop->_alloc_seq = nrn_point_prop_->_alloc_seq;
	_p = nrn_point_prop_->param;
	_ppvar = nrn_point_prop_->dparam;
 }else{
 	_p = nrn_prop_data_alloc(_mechtype, 24, _prop);
 	/*initialize range parameters*/
 	tauRise = 1;
 	tauFall = 1;
 	e = 0;
 	startDeprLevel = 1;
  }
 	_prop->param = _p;
 	_prop->param_size = 24;
  if (!nrn_point_prop_) {
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 3, _prop);
  }
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _net_receive(Point_process*, double*, double);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _DCNsynGABA_reg() {
	int _vectorized = 1;
  _initlists();
 	_pointtype = point_register_mech(_mechanism,
	 nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init,
	 hoc_nrnpointerindex, 1,
	 _hoc_create_pnt, _hoc_destroy_pnt, _member_func);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 24, 3);
  hoc_register_dparam_semantics(_mechtype, 0, "area");
  hoc_register_dparam_semantics(_mechtype, 1, "pntproc");
  hoc_register_dparam_semantics(_mechtype, 2, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 pnt_receive[_mechtype] = _net_receive;
 pnt_receive_size[_mechtype] = 1;
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 DCNsynGABA D:/NEURON models/DCN LuthmanEtAl2011 Stimulation Ef/mod_files/DCNsynGABA.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[2], _dlist1[2];
 static int state(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset = 0; {
   DA = - A / tauRise ;
   DB = - B / tauFall ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 DA = DA  / (1. - dt*( ( - 1.0 ) / tauRise )) ;
 DB = DB  / (1. - dt*( ( - 1.0 ) / tauFall )) ;
  return 0;
}
 /*END CVODE*/
 static int state (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) { {
    A = A + (1. - exp(dt*(( - 1.0 ) / tauRise)))*(- ( 0.0 ) / ( ( - 1.0 ) / tauRise ) - A) ;
    B = B + (1. - exp(dt*(( - 1.0 ) / tauFall)))*(- ( 0.0 ) / ( ( - 1.0 ) / tauFall ) - B) ;
   }
  return 0;
}
 
static void _net_receive (_pnt, _args, _lflag) Point_process* _pnt; double* _args; double _lflag; 
{  double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   _thread = (Datum*)0; _nt = (_NrnThread*)_pnt->_vnt;   _p = _pnt->_prop->param; _ppvar = _pnt->_prop->dparam;
  if (_tsav > t){ extern char* hoc_object_name(); hoc_execerror(hoc_object_name(_pnt->ob), ":Event arrived out of order. Must call ParallelContext.set_maxstep AFTER assigning minimum NetCon.delay");}
 _tsav = t; {
   deprLevel = giveFractionG ( _threadargs_ ) ;
       if (nrn_netrec_state_adjust && !cvode_active_){
    /* discon state adjustment for cnexp case (rate uses no local variable) */
    double __state = A;
    double __primary = (A + _args[0] * factor ) - __state;
     __primary += ( 1. - exp( 0.5*dt*( ( - 1.0 ) / tauRise ) ) )*( - ( 0.0 ) / ( ( - 1.0 ) / tauRise ) - __primary );
    A += __primary;
  } else {
 A = A + _args[0] * factor  ;
     }
     if (nrn_netrec_state_adjust && !cvode_active_){
    /* discon state adjustment for cnexp case (rate uses no local variable) */
    double __state = B;
    double __primary = (B + _args[0] * factor ) - __state;
     __primary += ( 1. - exp( 0.5*dt*( ( - 1.0 ) / tauFall ) ) )*( - ( 0.0 ) / ( ( - 1.0 ) / tauFall ) - __primary );
    B += __primary;
  } else {
 B = B + _args[0] * factor  ;
     }
 } }
 
double giveFractionG ( _threadargsproto_ ) {
   double _lgiveFractionG;
 if ( notFirstSpike ) {
     tSpikes [ 0 ] = tSpikes [ 1 ] ;
     tSpikes [ 1 ] = t ;
     ISI = tSpikes [ 1 ] - tSpikes [ 0 ] ;
     freq = 1000.0 / ISI ;
     relProbSS = 0.08 + 0.60 * exp ( - 2.84 * freq ) + 0.32 * exp ( - 0.02 * freq ) ;
     tau = 2.0 + 2500.0 * exp ( - 0.274 * freq ) + 100.0 * exp ( - 0.022 * freq ) ;
     relProb [ 1 ] = relProb [ 0 ] + ( relProbSS - relProb [ 0 ] ) * ( 1.0 - exp ( - ISI / tau ) ) ;
     relProb [ 0 ] = relProb [ 1 ] ;
     _lgiveFractionG = relProb [ 1 ] ;
     }
   else {
     tSpikes [ 1 ] = t ;
     relProb [ 0 ] = startDeprLevel ;
     notFirstSpike = 1.0 ;
     _lgiveFractionG = relProb [ 0 ] ;
     }
   
return _lgiveFractionG;
 }
 
static double _hoc_giveFractionG(void* _vptr) {
 double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   _p = ((Point_process*)_vptr)->_prop->param;
  _ppvar = ((Point_process*)_vptr)->_prop->dparam;
  _thread = _extcall_thread;
  _nt = (_NrnThread*)((Point_process*)_vptr)->_vnt;
 _r =  giveFractionG ( _p, _ppvar, _thread, _nt );
 return(_r);
}
 
static int _ode_count(int _type){ return 2;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
     _ode_spec1 (_p, _ppvar, _thread, _nt);
 }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 2; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _ode_matsol1 (_p, _ppvar, _thread, _nt);
 }
 
static void _ode_matsol(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
 _ode_matsol_instance1(_threadargs_);
 }}

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  A = A0;
  B = B0;
 {
   double _ltp ;
 if ( tauRise / tauFall > .9999 ) {
     tauRise = .9999 * tauFall ;
     }
   A = 0.0 ;
   B = 0.0 ;
   _ltp = ( tauRise * tauFall ) / ( tauFall - tauRise ) * log ( tauFall / tauRise ) ;
   factor = - exp ( - _ltp / tauRise ) + exp ( - _ltp / tauFall ) ;
   factor = 1.0 / factor ;
   notFirstSpike = 0.0 ;
   }
 
}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _tsav = -1e20;
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
 initmodel(_p, _ppvar, _thread, _nt);
}
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   g = ( B - A ) * deprLevel ;
   i = g * ( v - e ) ;
   }
 _current += i;

} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
 	}
 _g = (_g - _rhs)/.001;
 _g *=  1.e2/(_nd_area);
 _rhs *= 1.e2/(_nd_area);
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}
 
}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}
 
}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v=_v;
{
 {   state(_p, _ppvar, _thread, _nt);
  }}}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(A) - _p;  _dlist1[0] = &(DA) - _p;
 _slist1[1] = &(B) - _p;  _dlist1[1] = &(DB) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "DCNsynGABA.mod";
static const char* nmodl_file_text = 
  "COMMENT by Johannes Luthman:\n"
  "\n"
  "    This mechanism is based on DCNsyn.mod in this project. What's added here is\n"
  "    paired-pulse depression of the synapse's current, based on Shin et al, 2007\n"
  "    (PLOSone issue 5, e485, page 2), on which the changes in terminology\n"
  "    compared to DCNsyn.mod are based.\n"
  "    The depression is implemented via the change from [g = B - A] in DCNsyn.mod\n"
  "    to [g = (B - A) * deprLevel] here, and the calculation of deprLevel on each\n"
  "    input (NETRECEIVE).\n"
  "\n"
  "ENDCOMMENT\n"
  "\n"
  "NEURON {\n"
  "	POINT_PROCESS DCNsynGABA\n"
  "	NONSPECIFIC_CURRENT i\n"
  "	RANGE g, i, e, tauRise, tauFall, startDeprLevel, deprLevel\n"
  "}\n"
  "\n"
  "UNITS {\n"
  "	(nA) = (nanoamp)\n"
  "	(mV) = (millivolt)\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "	tauRise = 1 (ms)\n"
  "	tauFall = 1 (ms)\n"
  "	e = 0 (mV)\n"
  "	startDeprLevel = 1 : set this in hoc to the depression level reached at \n"
  "	        : steady state (use the equation for relProbSS, below) by the \n"
  "	        : used GABAergic input frequency.\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "    relProbSS (1) : This corresponds to Rss in the article (given in COMMENT at top).\n"
  "    relProb[2] (1) : This corresponds to Rn and Rn-1 in the article.\n"
  "    freq (1/s) : This corresponds to r in the article.\n"
  "    tau (ms)\n"
  "    tSpikes[2] (ms)\n"
  "    ISI (ms)\n"
  "    deprLevel (1) : level of synaptic depression. The conductance is\n"
  "                  : multiplied by this factor in BREAKPOINT.\n"
  "    notFirstSpike (1) : boolean used to set up values of previous step on first\n"
  "                      : call to this mechanism.\n"
  "\n"
  "	v (mV)\n"
  "	i (nA)\n"
  "	g (microsiemens)\n"
  "	factor\n"
  "}\n"
  "\n"
  "STATE {\n"
  "	A (microsiemens)\n"
  "	B (microsiemens)\n"
  "}\n"
  "\n"
  "INITIAL {\n"
  "	LOCAL tp\n"
  "	if (tauRise/tauFall > .9999) {\n"
  "		tauRise = .9999*tauFall\n"
  "	}\n"
  "	A = 0\n"
  "	B = 0\n"
  "	tp = (tauRise*tauFall)/(tauFall - tauRise) * log(tauFall/tauRise)\n"
  "	factor = -exp(-tp/tauRise) + exp(-tp/tauFall)\n"
  "	factor = 1/factor\n"
  "\n"
  "    notFirstSpike = 0\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "    : Here the conductance is updated each time step, while the NET_RECEIVE block\n"
  "    : is only invoked by being contacted by a NetCon object.\n"
  "  	SOLVE state METHOD cnexp\n"
  "   	g = (B - A) * deprLevel\n"
  "   	i = g*(v - e)   	\n"
  "}\n"
  "\n"
  "DERIVATIVE state {\n"
  "	A' = -A/tauRise\n"
  "	B' = -B/tauFall\n"
  "}\n"
  "\n"
  "NET_RECEIVE(weight (microsiemens)) {\n"
  "    deprLevel = giveFractionG()\n"
  "    state_discontinuity(A, A + weight*factor)\n"
  "	state_discontinuity(B, B + weight*factor)\n"
  "}\n"
  "\n"
  "FUNCTION giveFractionG() {\n"
  "	if (notFirstSpike) {\n"
  "        : Set the current spike to the present time, and calculate ISI as the\n"
  "        : difference in time from the last pass through here.\n"
  "        tSpikes[0] = tSpikes[1]\n"
  "        tSpikes[1] = t\n"
  "        ISI = tSpikes[1] - tSpikes[0]\n"
  "        freq = 1000 / ISI\n"
  "        \n"
  "        relProbSS = 0.08 + 0.60*exp(-2.84*freq) + 0.32*exp(-0.02*freq)\n"
  "        tau = 2 + 2500*exp(-0.274*freq) + 100*exp(-0.022*freq)\n"
  "        relProb[1] = relProb[0] + (relProbSS - relProb[0]) * (1-exp(-ISI/tau))\n"
  "        relProb[0] = relProb[1]\n"
  "\n"
  "        giveFractionG = relProb[1]\n"
  "	} else {\n"
  "	    tSpikes[1] = t\n"
  "	    relProb[0] = startDeprLevel\n"
  "	    notFirstSpike = 1\n"
  "	    giveFractionG = relProb[0]\n"
  "	}\n"
  "}\n"
  ;
#endif
