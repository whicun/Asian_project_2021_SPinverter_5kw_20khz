/***********************************************************************/
/*                                                                     */
/*  FILE        :parameter.h	                                       */
/*  DATE        :Jul 30, 2019       		                       */
/*  DESCRIPTION :Define all parameter		                       */
/*  CPU TYPE    :RX71M                                                 */
/*                                                                     */
/*                                                                     */
/***********************************************************************/
//===== First Iref ===========================================//
int fisrt_time = 1;      //must be 1
int PWM_IO_Enable = 0; //must be 0
int  PWM_IO_counter = 0;
//===== VDC_inspect ====================================//
int  VDC_inspect = 0 ;  //must be 0

//===== Current feedback ===============================//
int IiR_fb = 0;
int IiS_fb = 0;
int IiT_fb = 0;
int IgR_fb = 0;
int IgS_fb = 0;
int IgT_fb = 0;
int IDC_fb = 0;
int ILDR_fb = 0;
int ILDS_fb = 0;
int ILDT_fb = 0;

double  IiR_fbD = 0;
double  IiS_fbD = 0;
double  IiT_fbD = 0;
double  IgR_fbD = 0;
double  IgS_fbD = 0;
double  IgT_fbD = 0;



//===== Voltage feedback ===============================//
int VPR_fb = 0;
int VPS_fb = 0;
int VPT_fb = 0;
int VCR_fb = 0;
int VCS_fb = 0;
int VCT_fb = 0;
int FVDC_fb = 0 ;
int HVDC_fb = 0 ;
int GCVRN_fb = 0 ;
int GCVSN_fb = 0 ;
int GCVTN_fb = 0 ;
int tempR_fb = 0;
int tempS_fb = 0;
int tempT_fb = 0;




//===== Current(n-1) feedback ===============================//
int IiR_fb_1 = 0;
int IiS_fb_1 = 0;
int IiT_fb_1 = 0;
int IgR_fb_1 = 0;
int IgS_fb_1 = 0;
int IgT_fb_1 = 0;

double IiR_fb_1D = 0;
double IiS_fb_1D = 0;
double IiT_fb_1D = 0;
double IgR_fb_1D = 0;
double IgS_fb_1D = 0;
double IgT_fb_1D = 0;




//===== protection ========================================

unsigned char HPMdebounce = 0 ;
unsigned char HPM_protect = 0 ;
int swcounter = 0 ;
int protection_on =0;
unsigned int  wFVDC_error = 0;
unsigned int  wFVDC1_error = 0;
unsigned char wVPR_error = 0;
unsigned char wVPS_error = 0;
unsigned char wVPT_error = 0;
unsigned char wVCR_error = 0;
unsigned char wVCS_error = 0;
unsigned char wVCT_error = 0;

unsigned char wIiR_error = 0;
unsigned char wIiS_error = 0;
unsigned char wIiT_error = 0;
unsigned char wIgR_error = 0;
unsigned char wIgS_error = 0;
unsigned char wIgT_error = 0;
unsigned char wEmer_error = 0;
unsigned char wPow_error = 0;
unsigned char wIDC_error = 0;
unsigned char wTempR_error = 0;
unsigned char wTempS_error = 0;
unsigned char wTempT_error = 0;


int VacR_protectionCheck = 0;
double VPR_pro = 0;
double VPR_proerror = 0;



//=====dealy counter =========================================
unsigned int counter = 0;
unsigned int fordelay1 = 0;
unsigned int fordelay2 = 0;

//======UPS point counter=====================================
int UPS_counter_Rn =   -1;
int UPS_counter_Sn = 219;
int UPS_counter_Tn = 109;

//===== GC counter ===========================================
int  GC_counter_Rn =   -1;
int  GC_counter_Sn = 219;
int  GC_counter_Tn = 109;
int  GC_counter_Rn1 = 0;
int  GC_counter_Sn1 = 0;
int  GC_counter_Tn1 = 0;

//===== mode =================================================
unsigned char  operation_mode = 0;

//===== grid detection========================================
unsigned char freq_check = 0;                 // must set 0
unsigned char Seq_check = 0;                   // must set 0
unsigned int ZCVCR_H = 0;
unsigned int ZCVCR_L = 0;
unsigned int ZCVCR_H_Check = 0;
unsigned int ZCVCR_L_Check = 0;
unsigned char frqe_ckeck_counter = 0;  // must set 0
unsigned int R_Neg_counter  = 0;
unsigned char R_Neg_check = 0;               // must set 0
unsigned char R_Pos_debounce = 0;         // must set 0
unsigned char R_Zerocrossing_ok = 0;   // must set 0
unsigned char Debounce =  1;
unsigned char SDebounce =  0;
unsigned int S_Pos_counter = 0;
unsigned char S_Pos_check = 0;               // must set 0
unsigned char S_Neg_debounce = 0;         // must set 0
unsigned char S_Zerocrossing_ok = 0;   // must set 0
unsigned char RST_Check = 0;                  // must set 0    
unsigned char counter_equal = 0;          // must set 0
unsigned int ZCVCR_counter = 0;            // must set 0
unsigned char ZVCR_check = 0;                // must set 0
unsigned char ZVCR_debounce = 0;          // must set 0
unsigned char Grid_connected = 0;         // must set 0

//===== VDC_ready=============================================
unsigned char VDC_check = 0;                  // must set 0
unsigned int FVDC_check_counter = 0;
unsigned int HVDC_check_counter = 0;
unsigned int cycle_counter = 0;

//===== variable_L_detect ====================================
int IiR_fb_ana = 0;
int IiS_fb_ana = 0;
int IiT_fb_ana = 0;
int IgR_fb_ana = 0;
int IgS_fb_ana = 0;
int IgT_fb_ana = 0;

//===== Inductance ==========================================
double L_iR_attenu = 0;
double L_iS_attenu  = 0;
double L_iT_attenu  = 0;
double L_gR_attenu  = 0;
double L_gS_attenu  = 0;
double L_gT_attenu = 0;

//===== current reference ===================================
double IiR_ref1 = 0;
double IiS_ref1 = 0;
double IiT_ref1 = 0;

double delta_IiR = 0;
double delta_IiS = 0;
double delta_IiT = 0;

double delta_IiR_term = 0;
double delta_IiS_term = 0;
double delta_IiT_term = 0;

//===== Duty term ============================================
double CompGainR_Ii = 0;
double CompGainS_Ii = 0;
double CompGainT_Ii = 0;
double CompGainR_Ig = 0;
double CompGainS_Ig = 0;
double CompGainT_Ig = 0;

double IiCompR = 0;
double IiCompS = 0;
double IiCompT = 0;
double IgCompR = 0;
double IgCompS = 0;
double IgCompT = 0;

double VAC_R_term = 0;
double VAC_S_term = 0;
double VAC_T_term = 0;

int  swduty_R = 0;
int  swduty_S = 0;
int  swduty_T = 0;

int SVPWM_Max = 0;
int SVPWM_Min = 0;
int SVPWM = 0;

//===== power diamond ===========================================
double Kload = 0;
int change_load_counter = 0;  //must be 0
int max_kload_for_sure = 0;    //must be 0

//=====variable parameters======//
int dif_counter = 2 ; // per n(dif_counter) cycle to change kload
double rated_power = 0;
int max_kload_period = 1; //if this value set 1, rated power peroid cycle is (n+1)*dif_counter
double dif_kload = 0.5;     // chang n load 

//=====PFC ======================================================
int operating_PF = 0;
int PF_status = 0;// PF_normal 0   PF_leading 1   PF_lagging 2
int PF_phase = 0;
int phase_angle = 0; // for phase shift (degree / 360) * 330

//=====Cycle_sign_Interrupt======================================
short hiZCVPRsaved = 0; // the positive or negative of VPRn 
short hiZCVPSsaved = 0; // the positive or negative of VPSn
short hiZCVPTsaved = 0; // the positive or negative of VPTn

short hiZCVCRsaved = 0; // the positive or negative of VCRn
short hiZCVCSsaved = 0; // the positive or negative of VCSn
short hiZCVCTsaved = 0; // the positive or negative of VCTn

short hiZCIiRsaved = 0; // the positive or negative of IiR
short hiZCIiSsaved = 0; // the positive or negative of IiS
short hiZCIiTsaved = 0; // the positive or negative of IiT

short hiZCIgRsaved = 0; // the positive or negative of IgR
short hiZCIgSsaved = 0; // the positive or negative of IgS
short hiZCIgTsaved = 0; // the positive or negative of IgT 

short hiZCIDCsaved = 0; // the positive or negative of IDC 


//====== L table ===============================================
//20-Dec-2021 15:41:34
double L_table_Iin[46]={
1.0000,     0.9997,     0.999,     0.9977,     0.9961,     0.9941,     0.9917,     0.989,     0.9859,     0.9824,      
0.9786,     0.9745,     0.9701,   0.9655,     0.9605,     0.9552,     0.9498,     0.944,     0.9381,     0.9319,
0.9255,     0.9189,     0.9121,   0.9052,     0.8981,     0.8908,     0.8834,     0.8759,   0.8682,     0.8605,
0.8527,     0.8447,     0.8367,   0.8286,     0.8205,     0.8123,     0.8041,     0.7959,   0.7876,     0.7793
0.7710,     0.7627,     0.7544,   0.7461,     0.7378,     0.7295       };


//20-Dec-2021 15:45:14
double L_table_Ign[46]={
1.0000,     0.9999,     0.9996,     0.9992,     0.9986,     0.9978,     0.997,     0.9959,     0.9948,     0.9935,
0.9921,     0.9905,     0.9889,     0.9871,     0.9852,     0.9832,     0.981,     0.9788,     0.9764,     0.974, 
0.9714,     0.9687,     0.966,       0.9631,     0.9601,     0.9571,     0.9539,   0.9507,     0.9474,     0.944,
0.9405,     0.937,       0.9334,     0.9297,     0.9259,     0.9221,     0.9182,   0.9142,     0.9102,     0.9061
0.9020,     0.8978,     0.8936,     0.8893,     0.8849,     0.8806       };




//22-Dec-2021 14:59:24
double sine_V_table[330]={
//==============================0-109===================================//
63,         127,       190,       253,      316,       379,       442,       505,       567,      629,      
692,       753,       815,       876,      937,       998,       1058,     1118,     1177,     1236,      
1295,     1353,     1410,     1467,     1524,     1580,     1635,     1690,     1745,     1798,      
1851,     1903,     1955,     2006,     2056,     2105,     2154,     2202,     2249,     2295,      
2341,     2385,     2429,     2472,     2514,     2555,     2595,     2634,     2672,     2709,      
2745,     2781,     2815,     2848,     2880,     2911,     2942,     2971,     2999,     3025,      
3051,     3076,     3099,     3122,     3143,     3163,     3182,     3200,     3217,     3232,      
3247,     3260,     3272,     3282,     3292,     3301,     3308,     3314,     3319,     3322,      
3325,     3326,     3326,     3325,     3322,     3319,     3314,     3308,     3301,     3292,      
3282,     3272,     3260,     3247,     3232,     3217,     3200,     3182,     3163,     3143,      
//==============================110-219===================================//
3122,     3099,     3076,     3051,     3025,     2999,     2971,     2942,     2911,     2880,      
2848,     2815,     2781,     2745,     2709,     2672,     2634,     2595,     2555,     2514,      
2472,     2429,     2385,     2341,     2295,     2249,     2202,     2154,     2105,     2056,      
2006,     1955,     1903,     1851,     1798,     1745,     1690,     1635,     1580,     1524,      
1467,     1410,     1353,     1295,     1236,     1177,     1118,     1058,      998,       937,      
876,        815,       753,       692,       629,       567,      505,       442,       379,       316,      
253,        190,       127,        63,         0,         -63,      -127,     -190,     -253,     -316,      
-379,       -442,      -505,      -567,      -629,      -692,     -753,      -815,      -876,     -937,      
-998,      -1058,    -1118,    -1177,    -1236,    -1295,    -1353,    -1410,    -1467,    -1524,      
-1580,    -1635,    -1690,    -1745,    -1798,    -1851,    -1903,    -1955,    -2006,    -2056,      
    //==============================220-329===================================//
-2105,    -2154,    -2202,    -2249,    -2295,    -2341,    -2385,    -2429,    -2472,    -2514,      
-2555,    -2595,    -2634,    -2672,    -2709,    -2745,    -2781,    -2815,    -2848,    -2880,      
-2911,    -2942,    -2971,    -2999,    -3025,    -3051,    -3076,    -3099,    -3122,    -3143,      
-3163,    -3182,    -3200,    -3217,    -3232,    -3247,    -3260,    -3272,    -3282,    -3292,      
-3301,    -3308,    -3314,    -3319,    -3322,    -3325,    -3326,    -3326,    -3325,    -3322,      
-3319,    -3314,    -3308,    -3301,    -3292,    -3282,    -3272,    -3260,    -3247,    -3232,      
-3217,    -3200,    -3182,    -3163,    -3143,    -3122,    -3099,    -3076,    -3051,    -3025,      
-2999,    -2971,    -2942,    -2911,    -2880,    -2848,    -2815,    -2781,    -2745,    -2709,      
-2672,    -2634,    -2595,    -2555,    -2514,    -2472,    -2429,    -2385,    -2341,    -2295,      
-2249,    -2202,    -2154,    -2105,    -2056,    -2006,    -1955,    -1903,    -1851,    -1798,      
-1745,    -1690,    -1635,    -1580,    -1524,    -1467,    -1410,    -1353,    -1295,    -1236,      
-1177,    -1118,    -1058,      -998,     -937,      -876,      -815,      -753,      -692,      -629,      
 -567,      -505,      -442,      -379,     -316,      -253,      -190,      -127,        -63,          0
};





























