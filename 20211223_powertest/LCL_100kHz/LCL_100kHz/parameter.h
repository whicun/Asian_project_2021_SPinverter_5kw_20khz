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


int VacS_protectionCheck = 0;
double VPS_pro = 0;
double VPS_proerror = 0;



//=====dealy counter =========================================
unsigned int counter = 0;
unsigned int fordelay1 = 0;
unsigned int fordelay2 = 0;

//======UPS point counter=====================================
int UPS_counter_Rn =   -1;
int UPS_counter_Sn = 551;
int UPS_counter_Tn = 275;

//===== GC counter ===========================================
int  GC_counter_Rn =   -1;
int  GC_counter_Sn = 551;
int  GC_counter_Tn = 275;
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
int Kload = 0;
int change_load_counter = 0;  //must be 0
int max_kload_for_sure = 0;    //must be 0

//=====variable parameters======//
int dif_counter = 2 ; // per n(dif_counter) cycle to change kload
int rated_power = 5;
int max_kload_period = 1; //if this value set 1, rated power peroid cycle is (n+1)*dif_counter
int dif_kload = 1;     // chang n load 

//=====PFC ======================================================
int operating_PF = 0;
int PF_status = 0;// PF_normal 0   PF_leading 1   PF_lagging 2
int PF_phase = 0;
int phase_angle = 0; // for phase shift (degree / 360) * 828

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
//05-Nov-2019 15:21:07
double L_table_Ign[88]={
1,             0.9998,     0.9992,     0.9982,     0.9968,     0.995,       0.9928,     0.9902,     0.9873,     0.984,       0.9804,      
0.9764,    0.9721,     0.9674,     0.9625,     0.9572,     0.9516,     0.9458,     0.9397,     0.9333,     0.9267,     0.9199,      
0.9128,    0.9055,     0.898,       0.8904,     0.8826,     0.8746,     0.8665,     0.8582,     0.8499,     0.8414,     0.8328,      
0.8241,    0.8154,     0.8066,     0.7977,     0.7888,     0.7799,     0.7709,     0.7619,     0.7529,     0.7439,     0.735,      
0.726,      0.717,       0.7081,     0.6992,     0.6904,     0.6816,     0.6728,     0.6641,     0.6555,     0.6469,     0.6384,      
0.63,        0.6216,     0.6133,     0.6051,     0.597,       0.5889,     0.581,       0.5731,     0.5653,     0.5577,     0.5501,      
0.5426,    0.5352,     0.5279,     0.5206,     0.5135,     0.5065,     0.4996,     0.4927,     0.486,        0.4793,     0.4728,      
0.4663,    0.46,         0.4537,     0.4475,     0.4415,     0.4355,     0.4296,     0.4238,     0.4181,     0.4124,     0.4069
};

//05-Nov-2019 15:25:01
double L_table_Iin[88]={
1,              0.9995,     0.998,       0.9956,     0.9922,     0.9879,     0.9827,     0.9766,     0.9697,     0.9621,     0.9537,      
0.9446,     0.9348,     0.9245,     0.9136,     0.9021,     0.8903,     0.878,       0.8653,     0.8523,     0.839,       0.8255,      
0.8119,     0.798,       0.7841,     0.7701,     0.756,       0.742,       0.7279,     0.7139,     0.7,          0.6862,     0.6725,      
0.6589,     0.6455,     0.6323,     0.6192,     0.6063,     0.5936,     0.5811,     0.5689,     0.5568,     0.545,       0.5334,      
0.5221,     0.5109,     0.5001,     0.4894,     0.479,       0.4688,     0.4588,     0.4491,     0.4396,     0.4303,     0.4213,      
0.4124,     0.4038,     0.3954,     0.3872,     0.3792,     0.3714,     0.3637,     0.3563,     0.3491,     0.342,       0.3351,      
0.3284,     0.3219,     0.3155,     0.3093,     0.3032,     0.2973,     0.2916,     0.286,       0.2805,     0.2751,     0.2699,      
0.2649,     0.2599,     0.2551,     0.2504,     0.2458,     0.2413,     0.2369,     0.2327,     0.2285,     0.2244,     0.2205
};




//25-Sep-2020 10:18:09
double sine_V_table[828]={
    //========================== point 0 ~ 95 ==============================================//
25,         50,         76,        101,       126,       151,       177,       202,       227,      252,       277,      302,      
328,       353,       378,       403,      428,       453,       478,       503,       528,      553,       578,       602,      
627,       652,       677,       701,      726,       751,       775,       800,       824,      849,       873,       897,      
922,       946,       970,       994,      1018,     1042,     1066,     1090,     1114,     1138,     1161,     1185,      
1208,     1232,     1255,     1279,     1302,     1325,     1348,     1371,     1394,     1417,     1440,     1463,      
1485,     1508,     1530,     1553,     1575,     1597,     1619,     1641,     1663,     1685,     1706,     1728,      
1750,     1771,     1792,     1814,     1835,     1856,     1877,     1897,     1918,     1939,     1959,     1979,      
2000,     2020,     2040,     2060,     2079,     2099,     2118,     2138,     2157,     2176,     2195,     2214,  
      //========================== point 96 ~ 191 ==============================================//
2233,     2252,     2270,     2289,     2307,     2325,     2343,     2361,     2378,     2396,     2413,     2431,      
2448,     2465,     2482,     2498,     2515,     2532,     2548,     2564,     2580,     2596,     2612,     2627,      
2642,     2658,     2673,     2688,     2703,     2717,     2732,     2746,     2760,     2774,     2788,     2802,      
2815,     2829,     2842,     2855,     2868,     2880,     2893,     2905,     2917,     2929,     2941,     2953,      
2965,     2976,     2987,     2998,     3009,     3020,     3030,     3040,     3051,     3061,     3070,     3080,      
3089,     3099,     3108,     3117,     3125,     3134,     3142,     3150,     3158,     3166,     3174,     3181,      
3189,     3196,     3203,     3209,     3216,     3222,     3228,     3234,     3240,     3246,     3251,     3256,      
3261,     3266,     3271,     3275,     3280,     3284,     3288,     3291,     3295,     3298,     3301,     3304,      
      //========================== point 192 ~ 287 ==============================================//
3307,     3310,     3312,     3314,     3316,     3318,     3320,     3321,     3323,     3324,     3324,     3325,      
3326,     3326,     3326,     3326,     3326,     3325,     3324,     3324,     3323,     3321,     3320,     3318,      
3316,     3314,     3312,     3310,     3307,     3304,     3301,     3298,     3295,     3291,     3288,     3284,      
3280,     3275,     3271,     3266,     3261,     3256,     3251,     3246,     3240,     3234,     3228,     3222,      
3216,     3209,     3203,     3196,     3189,     3181,     3174,     3166,     3158,     3150,     3142,     3134,      
3125,     3117,     3108,     3099,     3089,     3080,     3070,     3061,     3051,     3040,     3030,     3020,      
3009,     2998,     2987,     2976,     2965,     2953,     2941,     2929,     2917,     2905,     2893,     2880,      
2868,     2855,     2842,     2829,     2815,     2802,     2788,     2774,     2760,     2746,     2732,     2717,      
      //========================== point 288 ~ 383 ==============================================//
2703,     2688,     2673,     2658,     2642,     2627,     2612,     2596,     2580,     2564,     2548,     2532,      
2515,     2498,     2482,     2465,     2448,     2431,     2413,     2396,     2378,     2361,     2343,     2325,      
2307,     2289,     2270,     2252,     2233,     2214,     2195,     2176,     2157,     2138,     2118,     2099,      
2079,     2060,     2040,     2020,     2000,     1979,     1959,     1939,     1918,     1897,     1877,     1856,      
1835,     1814,     1792,     1771,     1750,     1728,     1706,     1685,     1663,     1641,     1619,     1597,      
1575,     1553,     1530,     1508,     1485,     1463,     1440,     1417,     1394,     1371,     1348,     1325,      
1302,     1279,     1255,     1232,     1208,     1185,     1161,     1138,     1114,     1090,     1066,     1042,      
1018,     994,       970,       946,       922,       897,       873,       849,      824,       800,       775,       751,      
      //========================== point 384 ~ 479 ==============================================//
726,         701,         677,        652,        627,         602,         578,          553,        528,         503,         478,        453,      
428,         403,         378,        353,        328,         302,         277,          252,        227,         202,         177,        151,      
126,         101,         76,          50,          25,           0,            -25,          -50,        -76,         -101,       -126,      -151,      
-177,       -202,       -227,      -252,       -277,       -302,       -328,       -353,       -378,       -403,       -428,      -453,      
-478,       -503,       -528,      -553,       -578,       -602,       -627,       -652,       -677,       -701,       -726,      -751,      
-775,       -800,       -824,      -849,       -873,       -897,       -922,       -946,       -970,       -994,       -1018,    -1042,      
-1066,     -1090,     -1114,     -1138,     -1161,     -1185,     -1208,     -1232,     -1255,     -1279,     -1302,     -1325,      
-1348,     -1371,     -1394,     -1417,     -1440,     -1463,     -1485,     -1508,     -1530,     -1553,     -1575,     -1597,      
      //========================== point 480 ~ 575 ==============================================//
-1619,     -1641,     -1663,     -1685,     -1706,     -1728,     -1750,     -1771,     -1792,     -1814,     -1835,     -1856,      
-1877,     -1897,     -1918,     -1939,     -1959,     -1979,     -2000,     -2020,     -2040,     -2060,     -2079,     -2099,      
-2118,     -2138,     -2157,     -2176,     -2195,     -2214,     -2233,     -2252,     -2270,     -2289,     -2307,     -2325,      
-2343,     -2361,     -2378,     -2396,     -2413,     -2431,     -2448,     -2465,     -2482,     -2498,     -2515,     -2532,      
-2548,     -2564,     -2580,     -2596,     -2612,     -2627,     -2642,     -2658,     -2673,     -2688,     -2703,     -2717,      
-2732,     -2746,     -2760,     -2774,     -2788,     -2802,     -2815,     -2829,     -2842,     -2855,     -2868,     -2880,      
-2893,     -2905,     -2917,     -2929,     -2941,     -2953,     -2965,     -2976,     -2987,     -2998,     -3009,     -3020,      
-3030,     -3040,     -3051,     -3061,     -3070,     -3080,     -3089,     -3099,     -3108,     -3117,     -3125,     -3134,      
      //========================== point 576 ~ 671 ==============================================//
-3142,     -3150,     -3158,     -3166,     -3174,     -3181,     -3189,     -3196,     -3203,     -3209,     -3216,     -3222,      
-3228,     -3234,     -3240,     -3246,     -3251,     -3256,     -3261,     -3266,     -3271,     -3275,     -3280,     -3284,      
-3288,     -3291,     -3295,     -3298,     -3301,     -3304,     -3307,     -3310,     -3312,     -3314,     -3316,     -3318,      
-3320,     -3321,     -3323,     -3324,     -3324,     -3325,     -3326,     -3326,     -3326,     -3326,     -3326,     -3325,      
-3324,     -3324,     -3323,     -3321,     -3320,     -3318,     -3316,     -3314,     -3312,     -3310,     -3307,     -3304,      
-3301,     -3298,     -3295,     -3291,     -3288,     -3284,     -3280,     -3275,     -3271,     -3266,     -3261,     -3256,      
-3251,     -3246,     -3240,     -3234,     -3228,     -3222,     -3216,     -3209,     -3203,     -3196,     -3189,     -3181,      
-3174,     -3166,     -3158,     -3150,     -3142,     -3134,     -3125,     -3117,     -3108,     -3099,     -3089,     -3080,      
      //========================== point 672 ~ 767 ==============================================//
-3070,     -3061,     -3051,     -3040,     -3030,     -3020,     -3009,     -2998,     -2987,     -2976,     -2965,     -2953,      
-2941,     -2929,     -2917,     -2905,     -2893,     -2880,     -2868,     -2855,     -2842,     -2829,     -2815,     -2802,      
-2788,     -2774,     -2760,     -2746,     -2732,     -2717,     -2703,     -2688,     -2673,     -2658,     -2642,     -2627,      
-2612,     -2596,     -2580,     -2564,     -2548,     -2532,     -2515,     -2498,     -2482,     -2465,     -2448,     -2431,      
-2413,     -2396,     -2378,     -2361,     -2343,     -2325,     -2307,     -2289,     -2270,     -2252,     -2233,     -2214,      
-2195,     -2176,     -2157,     -2138,     -2118,     -2099,     -2079,     -2060,     -2040,     -2020,     -2000,     -1979,      
-1959,     -1939,     -1918,     -1897,     -1877,     -1856,     -1835,     -1814,     -1792,     -1771,     -1750,     -1728,      
-1706,     -1685,     -1663,     -1641,     -1619,     -1597,     -1575,     -1553,     -1530,     -1508,     -1485,     -1463,      
      //========================== point 768 ~ 827 ==============================================//
-1440,     -1417,     -1394,     -1371,     -1348,     -1325,     -1302,     -1279,     -1255,     -1232,     -1208,     -1185,      
-1161,     -1138,     -1114,     -1090,     -1066,     -1042,     -1018,     -994,       -970,       -946,       -922,       -897,      
-873,       -849,       -824,       -800,       -775,       -751,       -726,       -701,      -677,       -652,       -627,       -602,      
-578,       -553,       -528,       -503,       -478,       -453,       -428,       -403,      -378,       -353,       -328,       -302,      
-277,       -252,       -227,       -202,       -177,       -151,       -126,       -101,      -76,         -50,         -25,         0
};

























