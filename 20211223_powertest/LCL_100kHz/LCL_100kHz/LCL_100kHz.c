/***********************************************************************/
/*                                                                     */
/*  FILE        :Main.c or Main.cpp(Bottom/Inductor30)                                    */
/*  DATE        :Tue, Oct 31, 2006                                     */
/*  DESCRIPTION :Main Program                                          */
/*  CPU TYPE    :                                                      */
/*                                                                     */
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/

#include "machine.h"
#include "iodefine.h"
#include "hwsetup.h"
#include "math.h"
#include "mathf.h"
#include "vect.h"
#include "typedefine.h"
#include "parameter.h"

//#include "typedefine.h"
#ifdef __cplusplus
//#include <ios>                        // Remove the comment when you use ios
//_SINT ios_base::Init::init_cnt;       // Remove the comment when you use ios
#endif


#ifdef __cplusplus
extern "C" {
void abort(void);
}
#endif

//======= Primary program ================================//
void main(void);

//======= A/D interrupt subprogram =======================//
void S12AD_Interrupt(void) ;
void S12AD1_Interrupt(void) ;
void Cycle_sign_Interrupt(void);

//======= protection subprogram ==========================//
void dc_vol_detection(void);
void over_detect(void) ;
void Preover_detect(void) ;
void protection(void) ;
void hw_detection(void) ;
void finish_PWM(void);
//===== Grid detection====================================//
void grid_detection(void);
void Grid_freq_detemination(void);
void Grid_Seq_detemination(void);
//===== DC detection =====================================//
void VDC_ready(void);
//===== GC mode subprogram ===============================//
void Grid_counter_range(void);
void Grid_mode_power(void);
void phase_shift(void);
//===== usual subprogram =================================//
void variable_L_detect(void);
void voltage_current_reference(void);
void setting_PWM_IO(void);
void Iref1_calculation(void);
void Iref_calculation(void);
void duty_calculation(void);
void LED_display(void);
void LEDScope(void);


//0225edit add LED
union {
    unsigned char FAULT ;
    struct {
        unsigned char F1:1 ;	// LED1
        unsigned char F2:1 ;	// LED2
        unsigned char F3:1 ;	// LED3
        unsigned char F4:1 ;	// LED4
        unsigned char F5:1 ;	// LED5
        unsigned char :5 ;
    } ;
} LED ;

union {
    int scope;
    struct {
        int F1:1;
        int F2:1;
        int F3:1;
        int F4:1;
        int F5:1;
        int F6:1;
        int F7:1;
        int F8:1;
        int F9:1;
        int F10:1;
        int F11:1;
        int F12:1;
        int F13:1;
        int F14:1;
        int F15:1;
        int F16:1;
    } ;
} bbLED;//LEDScope


 void main(void) {
    power_on = 1;                                       //show the cpu on and run program
    VDC_inspect = 0;
    dc_vol_detection();                         // detect 370 < VDC < 390 //01-Nov-2019 22:16:19
    hoVDC = 1;                                           // VDC inspection  OK
    Relay = 1;                                          // Relay turn on
    for(fordelay1=0; fordelay1 <= 80000; fordelay1++) {
        for(fordelay2=0; fordelay2 <= 1000; fordelay2++) {
        }

    }                                                         // delay for 0.3s

    operation_mode = AC_detection;    // detect AC freq and Seq   //0225edit start is ac_detect
    IR(PERIB, INTB128) = 0;
    IEN(PERIB, INTB128) = 1;                          // enable AD120 interrupt

    while(1) {
        LED_display() ;                                    //0225edit add LED display
        if(protection_on == 1 ) {
            protection();
            if(HPM_protect >= 2) {
                Hardware_portection=1;
            }
        }
    }
}

void S12AD_Interrupt(void) {
    //LED1=1;
    //LED2=1;
    IR(PERIB, INTB128) = 0;

    if( VDC_inspect == 0) {
        IiR_fb = (S12AD.ADDR0 - 2027);      //0225edit S12AD first S12AD1 later  //24-Sep-2020 22:56:19 
        //IiS_fb = (S12AD.ADDR1 - 2014);      //bias = 1.6327 V                    //24-Sep-2020 22:56:19
        //IiT_fb = (S12AD.ADDR2 - 2021);      //22-Nov-2019 16:38:19               //24-Sep-2020 22:56:19
        IDC_fb = S12AD.ADDR3 ;
        //FVDC_fb = S12AD.ADDR7 ;
        HVDC_fb = S12AD1.ADDR15 ;
        IgR_fb = (S12AD1.ADDR0 - 1996);        //24-Sep-2020 22:38:19
        //IgS_fb = (S12AD1.ADDR1 - 2022);        //24-Sep-2020 22:38:19
        //IgT_fb = (S12AD1.ADDR2 - 2016);       //24-Sep-2020 22:38:19
        tempR_fb = S12AD1.ADDR6 ;       //13-Sep-2021 15:28:19
        tempS_fb = S12AD1.ADDR7 ;       //13-Sep-2021 15:28:19
        //tempT_fb = S12AD1.ADDR8 ;       //13-Sep-2021 15:28:19

        Preover_detect();     //27-Feb-2020 22:56:19

        LED_display() ;
        
    } else {

        S12AD1_Interrupt();
    }

  //LEDScope();
  //LED1=0;
}

void S12AD1_Interrupt(void) {        // 20190131 edit
    IR(PERIB, INTB129) = 0;

    IiR_fb = (S12AD.ADDR0 - 2027);      //0225edit S12AD first S12AD1 later  //24-Sep-2020 22:56:19 
    //IiS_fb = (S12AD.ADDR1 - 2014);      //bias = 1.6327 V                    //24-Sep-2020 22:56:19
    //IiT_fb = (S12AD.ADDR2 - 2021);      //22-Nov-2019 16:38:19               //24-Sep-2020 22:56:19

  /*
     IiR_fb=sine_V_table[GC_counter_Rn] * V2A_ratio *Kload;
     IiS_fb=sine_V_table[GC_counter_Sn] * V2A_ratio *Kload;
     IiT_fb=-IiR_fb- IiS_fb;
     */
      /* IiR_fb = S12AD.ADDR0 ;      
       IiS_fb = S12AD.ADDR1 ;      //bias = 1.6327 V
       IiT_fb = S12AD.ADDR2 ;
    */


    IDC_fb = S12AD.ADDR3 ;
    VPR_fb = S12AD.ADDR4 ;
    //VPS_fb = S12AD.ADDR5 ;
    //VPT_fb = S12AD.ADDR6 ;
   //FVDC_fb = S12AD.ADDR7 ;
    HVDC_fb = S12AD1.ADDR15 ;
    
    IgR_fb = (S12AD1.ADDR0 - 1996);        //24-Sep-2020 22:38:19
  //IgS_fb = (S12AD1.ADDR1 - 2022);        //24-Sep-2020 22:38:19
  //IgT_fb = (S12AD1.ADDR2 - 2016);       //24-Sep-2020 22:38:19

    tempR_fb = S12AD1.ADDR6 ;       //13-Sep-2021 15:28:19
    tempS_fb = S12AD1.ADDR7 ;       //13-Sep-2021 15:28:19
    //tempT_fb = S12AD1.ADDR8 ;       //13-Sep-2021 15:28:19
 /*
    IgR_fb = S12AD1.ADDR0 ;
    IgS_fb = S12AD1.ADDR1 ;
    IgT_fb = S12AD1.ADDR2 ; 
*/
    /*
    IgR_fb=sine_V_table[GC_counter_Rn] * V2A_ratio *Kload;
    IgS_fb=sine_V_table[GC_counter_Sn] * V2A_ratio *Kload;
    IgT_fb=-IgR_fb- IgS_fb;
                            */
    VCR_fb = S12AD1.ADDR9 ;
    //VCS_fb = S12AD1.ADDR10 ;
    //VCT_fb = S12AD1.ADDR11 ;

    VPR_pro = VCR_fb;
    // ILDR_fb = S12AD1.ADDR6 ;
    // ILDS_fb = S12AD1.ADDR7 ;
    // ILDT_fb = S12AD1.ADDR8 ;
    // GCVRN_fb = S12AD1.ADDR12 ;
    // GCVSN_fb = S12AD1.ADDR13 ;
    // GCVTN_fb = S12AD1.ADDR14 ;



    if(operation_mode == AC_detection) {

        grid_detection();
    } else {
        if(VDC_check == 0) {
            VDC_ready();
        } else if(VDC_check == 1) {
            if(cycle_counter >= 5) {
                voltage_current_reference();
                if(fisrt_time == 1) {
                    Grid_counter_range();
                    Iref1_calculation();
                    L_iR_attenu = 1;
                    //L_iS_attenu = 1;
                    //L_iT_attenu = 1;
                    L_gR_attenu = 1;
                    //L_gS_attenu = 1;
                    //L_gT_attenu = 1;
                    fisrt_time = 0;
                }
                duty_calculation();
                Iref_calculation();
            }

            if(ZCVCR == 0) {
                ZCVCR_counter ++ ;
                if( ZCVCR_counter >= wait_cycle ) {
                    ZVCR_check = 1;
                }
            }
            if(ZCVCR == 1 && ZVCR_check == 1) {

                Debounce = 1;
                for(counter = 0; counter < 12 ; counter++) {
                    Debounce &= ZCVCR ;
                }

                if( Debounce == 1) {
                    ZVCR_check = 0;
                    ZCVCR_counter = 0;

                    cycle_counter ++ ;

                    if(fisrt_time == 1) {
                        GC_counter_Rn = ini_R_counter ;
                        GC_counter_Sn = ini_S_counter ;
                        GC_counter_Tn = ini_T_counter ;
                        UPS_counter_Rn = ini_R_counter ;
                        UPS_counter_Sn = ini_S_counter ;
                        UPS_counter_Tn = ini_T_counter ;

                    }
                    if(fisrt_time == 0) {
                        GC_counter_Rn = ini_R_counter + 1;
                        GC_counter_Sn = ini_S_counter + 1;
                        GC_counter_Tn = ini_T_counter + 1 ;
                        UPS_counter_Rn = ini_R_counter + 1;
                        UPS_counter_Sn = ini_S_counter + 1 ;
                        UPS_counter_Tn = ini_T_counter + 1;

                    }


                    if(cycle_counter >= 20) {
                        Grid_mode_power();
                        phase_shift();
                    }

                    if(cycle_counter >= 5) {
                        if(PWM_IO_Enable == 0) {
                            PWM_IO_counter ++;
                        }
                    }

                    if(PWM_IO_counter >=100 ) {
                        setting_PWM_IO();
                        PWM_IO_Enable = 1;
                    }
                }

            }

        }
    }
    over_detect();
}

void Cycle_sign_Interrupt(void) {
  /*  LED3=1;*/
  //hostart_up=1;

    hiZCVPRsaved = ZCVPR ;
    hiZCVPSsaved = ZCVPS ;
    hiZCVPTsaved = ZCVPT ;
    hiZCVCRsaved = ZCVCR;
    hiZCVCSsaved = ZCVCS;
    hiZCVCTsaved = ZCVCT;

    /* hiZCIiRsaved = ZCIiR;
     hiZCIiSsaved = ZCIiS;
     hiZCIiTsaved = ZCIiT;
     hiZCIgRsaved = ZCIgR;
     hiZCIgSsaved = ZCIgS;
     hiZCIgTsaved = ZCIgT;
    */
    hiZCIDCsaved = ZCIDC;

    IR(PERIA, INTA210) = 0;
    IEN(PERIA, INTA210) = 1;//enable Cycle_sign_Interrupt
   /* LED3=0;*/
   //hostart_up=0;
}

void Grid_mode_power(void) {
    if ( cycle_counter > start_counter ) {

        change_load_counter ++;
        if(change_load_counter == dif_counter) {
            if ( Kload < rated_power && max_kload_for_sure < max_kload_period ) {
                Kload = Kload + dif_kload ;
            } else if( Kload >= rated_power && max_kload_for_sure < max_kload_period) {
                Kload = rated_power;
                max_kload_for_sure ++;
            } else if ( max_kload_for_sure == max_kload_period) {
                Kload = Kload - dif_kload ;
            }

            change_load_counter = 0 ;
        }
        if(Kload < 0 ) {
            Kload = 0   ;
            finish_PWM();
        }
    }
}

void phase_shift(void) {

    operating_PF = PF_status ;
    PF_phase = phase_angle ;

    if ( operating_PF == PF_leading ) {
        PF_phase = PF_phase ;
    } else if ( operating_PF == PF_lagging ) {
        PF_phase = -1 * PF_phase ;
    }

    GC_counter_Rn = GC_counter_Rn + PF_phase ;
    GC_counter_Sn = GC_counter_Sn + PF_phase ;
    GC_counter_Tn = GC_counter_Tn + PF_phase ;

    if ( GC_counter_Rn >= max_counter ) {
        GC_counter_Rn = GC_counter_Rn - max_counter ;
    } else if ( GC_counter_Rn < 0 ) {
        GC_counter_Rn = GC_counter_Rn + max_counter ;
    }

    if ( GC_counter_Sn >= max_counter ) {
        GC_counter_Sn = GC_counter_Sn - max_counter ;
    } else if ( GC_counter_Sn < 0 ) {
        GC_counter_Sn = GC_counter_Sn + max_counter ;
    }

    if ( GC_counter_Tn >= max_counter ) {
        GC_counter_Tn = GC_counter_Tn - max_counter ;
    } else if ( GC_counter_Tn < 0 ) {
        GC_counter_Tn = GC_counter_Tn + max_counter ;
    }

}

void  dc_vol_detection(void) {
    //clear and disable all PWM output
    PWMRH_IO = 0;
    PWMRH_EN = 0;
    PWMSH_IO = 0;
    PWMSH_EN = 0;
    PWMTH_IO = 0;
    PWMTH_EN = 0;
    PWMRL_IO = 0;
    PWMRL_EN = 0;
    PWMSL_IO = 0;
    PWMSL_EN = 0;
    PWMTL_IO = 0;
    PWMTL_EN = 0;
    PWMNH_IO = 0;
    PWMNH_EN = 0;
    PWMNL_IO = 0;
    PWMNL_EN = 0;
    GPT.GTSTR.WORD = 0x000F;  //Start PWM counter
    IR(PERIB, INTB128) = 0;
    IEN(PERIB, INTB128) = 1; //enable AD120 interrupt and can renew value of feedback(FVDC_fb, HVDC_fb)

    for(counter = 0; counter < 2400000 ; counter++){} //delay for 0.01s
        while(HVDC_fb < HVDC_Ini ){
            hoVDC = 0;
        }       //377V FVDC_A2D Ratio 9.4961 //01-Nov-2019 22:16:19

            for(counter = 0; counter < 2400000 ; counter++){} //delay for 0.01s
                while(HVDC_fb < HVDC_Ini  ){
                    hoVDC = 0;
                }     //check for two times
                

    IR(PERIB, INTB128) = 0;
    IEN(PERIB, INTB128) = 0;  //disable AD120 interrupt

    VDC_inspect = 1;     // if enter AD120,and then it will enter AD121

}

void grid_detection(void) {
    UPS_counter_Rn ++ ;      //0225edit confirm initial value
    //UPS_counter_Sn ++ ;
    //UPS_counter_Tn ++ ;
    if ( UPS_counter_Rn >= max_counter ) {
        UPS_counter_Rn = 0 ;
    }
    /*if ( UPS_counter_Sn >= max_counter ) {
        UPS_counter_Sn = 0 ;
    }
    if ( UPS_counter_Tn >= max_counter ) {
        UPS_counter_Tn = 0 ;
    }
  */
    if(freq_check == 0) {

        Grid_freq_detemination();
    }

    /*if(freq_check == 1 && Seq_check == 0) {
        Grid_Seq_detemination();
    }*/

    if(freq_check == 1 ) {
        hoVAC_ok = 1;
        if ( counter_equal == 0 ) {
            UPS_counter_Rn ++ ;
            //UPS_counter_Sn ++ ;
           //UPS_counter_Tn ++ ;
        }

        if(ZCVCR == 1 && ZVCR_check == 1) {

            Debounce = 1;
            for(counter = 0; counter < 12 ; counter++) {
                Debounce &= ZCVCR ;
            }
            if( Debounce == 1) {
                ZVCR_check = 0;
                ZCVCR_counter = 0;
                GC_counter_Rn = ini_R_counter ;      //0225edit confirm initial value
                //GC_counter_Sn = ini_S_counter ;      //0225edit confirm GC_counter value
                //GC_counter_Tn = ini_T_counter ;

                if(counter_equal == 1) {
                    Grid_connected ++ ;
                    UPS_counter_Rn = R_counter1 ;     //0225edit check counter1 value
                    //UPS_counter_Sn = S_counter1 ;
                    //UPS_counter_Tn = T_counter1 ;
                }
            }
        }
        if(ZCVCR == 0) {
            ZCVCR_counter ++ ;
            if( ZCVCR_counter >= wait_cycle ) {
                ZVCR_check = 1;
            }
        }
        GC_counter_Rn ++ ;
        //GC_counter_Sn ++ ;
        //GC_counter_Tn ++ ;

        if ( GC_counter_Rn >= max_counter ) {
            GC_counter_Rn = 0 ;
        }
        /*if ( GC_counter_Sn >= max_counter ) {
            GC_counter_Sn = 0 ;
        }
        if ( GC_counter_Tn >= max_counter ) {
            GC_counter_Tn = 0 ;
        }*/


        if(Grid_connected >= 1) 
            {
            if(UPS_counter_Rn != GC_counter_Rn )
                /*(UPS_counter_Rn != GC_counter_Rn 
           ||UPS_counter_Sn != GC_counter_Sn
           ||UPS_counter_Tn != GC_counter_Tn)*/
                {
                Grid_connected = 0;
                counter_equal = 0 ;
                }
             }



        if (UPS_counter_Rn == GC_counter_Rn ) 
            /*(UPS_counter_Rn == GC_counter_Rn 
         &&UPS_counter_Sn == GC_counter_Sn
         &&UPS_counter_Tn == GC_counter_Tn)*/
            {
            counter_equal = 1 ;
            }
    }

    if( Grid_connected >= 5) {
        //hostart_up = 0;
        ZCVCR_counter = 0;
        ZVCR_check = 0;
        operation_mode = start_up;
    }
}


void Grid_freq_detemination(void) {


    if(ZCVCR == 1) {
        ZCVCR_H ++;
        if(ZCVCR_H == ZVCR_Counter) {
            ZCVCR_L_Check =  ZCVCR_L;
            ZCVCR_L = 0;
        }
        if(frqe_ckeck_counter >= 1) {
            if(ZCVCR_L_Check  > ZVCR_60_max ) {
                frqe_ckeck_counter = 0;
            }
        }
    }

    else {
        ZCVCR_L ++;
        if(ZCVCR_L == ZVCR_Counter) {
            ZCVCR_H_Check =  ZCVCR_H;
            ZCVCR_H = 0;
        }
        if(frqe_ckeck_counter >= 1) {
            if(ZCVCR_H_Check > ZVCR_60_max ) {
                frqe_ckeck_counter = 0;
            }
        }
    }

    if( ZVCR_60_min <= ZCVCR_H_Check && ZCVCR_H_Check <= ZVCR_60_max &&
            ZVCR_60_min <= ZCVCR_L_Check && ZCVCR_L_Check <= ZVCR_60_max) {
        frqe_ckeck_counter ++;        //0225edit clear ZCVCR_HL check
        ZCVCR_H_Check = 0;
        ZCVCR_L_Check = 0;


        if(frqe_ckeck_counter >= Grid_fre_for_sure) {
            freq_check = fre_60Hz;     //0225edit add LED(spare2) clear ZCVCR_HL check

        }
    }
}
/*
void Grid_Seq_detemination(void) {

    if(ZCVCR == 0) {
        R_Neg_counter ++;
        if(R_Neg_counter >= wait_cycle ) {
            R_Neg_check = 1;
        }
    }
    if(ZCVCR == 1 && R_Neg_check == 1) {
        Debounce = 1;
        for(counter = 0; counter < 12 ; counter++) {
            Debounce &= ZCVCR ;
        }
        if(Debounce == 1) {
            R_Pos_debounce ++ ;
        } else {
            R_Pos_debounce = 0;
        }
    }
    if( R_Pos_debounce >= 5) {
        R_Pos_debounce = 0;
        R_Neg_check = 0;
        R_Zerocrossing_ok = 1;        //confirm Zerocrossing of R
        R_Neg_counter = 0;
        GC_counter_Rn = ini_R_counter ;
    }
    GC_counter_Rn ++;                   //use GC_counter_Rn to check sequence


    if(ZCVCS == 1 &&  R_Zerocrossing_ok == 1) {
        S_Pos_counter ++;
        if(S_Pos_counter >= wait_cycle) {
            S_Pos_check = 1;
        }
    }

    if(ZCVCS == 0 && S_Pos_check == 1) {
        SDebounce = 0;
        for(counter = 0; counter < 12 ; counter++) {
            SDebounce += ZCVCS ;   //0225edit confirm
        }
        if(SDebounce == 0) {
            S_Neg_debounce ++ ;
        } else {
            S_Neg_debounce = 0;
        }
    }
    if( S_Neg_debounce >= 5) {
        S_Neg_debounce = 0;
        S_Pos_check = 0;
        S_Zerocrossing_ok = 1;       //confirm Zerocrossing(High to low) of S
        S_Pos_counter = 0;
    }

    if(R_Zerocrossing_ok == 1 && S_Zerocrossing_ok ==1) {       //0225edit check counter needs to add 5 point and s zero crossing
        if(sequence_min >= GC_counter_Rn || GC_counter_Rn >= sequence_max ) {
            RST_Check = 0;
            R_Zerocrossing_ok = 0;
            S_Zerocrossing_ok = 0;
        }
        if(sequence_min <= GC_counter_Rn && GC_counter_Rn <= sequence_max ) {
            RST_Check ++;
            R_Zerocrossing_ok = 0;
            S_Zerocrossing_ok = 0;
            if(RST_Check >= 5) {
                Seq_check = 1;       //0225edit clear counter Rn
            }
        }
    }
}
*/
void VDC_ready(void) {
    if(HVDC_fb > HVDC_Ini && HVDC_fb < HVDC_max ) {     //01-Nov-2019 22:16:19
        HVDC_check_counter ++;
        if(HVDC_check_counter >=  VDC_for_sure ) {    //01-Nov-2019 22:16:19
            HVDC_check_counter = 0;
            VDC_check = 1;
        }
    }
}

void Grid_counter_range(void) {
    //========= GC current counter (n)th state ==============//
    GC_counter_Rn ++ ;
    //GC_counter_Sn ++ ;
   //GC_counter_Tn ++ ;

    if ( GC_counter_Rn >= max_counter ) {
        GC_counter_Rn = 0 ;
    }
    /*if ( GC_counter_Sn >= max_counter ) {
        GC_counter_Sn = 0 ;
    }
    if ( GC_counter_Tn >= max_counter ) {
        GC_counter_Tn = 0 ;
    }*/
    //========= GC current counter (n+1)th state ============//
    GC_counter_Rn1 = GC_counter_Rn + 1 ;
    //GC_counter_Sn1 = GC_counter_Sn + 1 ;
    //GC_counter_Tn1 = GC_counter_Tn + 1 ;
    if ( GC_counter_Rn1 >= max_counter ) {
        GC_counter_Rn1 = 0 ;
    }
    /*if ( GC_counter_Sn1 >= max_counter ) {
        GC_counter_Sn1 = 0 ;
    }
    if ( GC_counter_Tn1 >= max_counter ) {
        GC_counter_Tn1= 0 ;
    }*/
    //========= UPS counter (n)th state ==============//
    UPS_counter_Rn ++ ;
    //UPS_counter_Sn ++ ;
    //UPS_counter_Tn ++ ;
    if ( UPS_counter_Rn >= max_counter ) {
        UPS_counter_Rn = 0 ;
    }
    /*if ( UPS_counter_Sn >= max_counter ) {
        UPS_counter_Sn = 0 ;
    }
    if ( UPS_counter_Tn >= max_counter ) {
        UPS_counter_Tn = 0 ;
    }*/

    VacR_protectionCheck = 1;
}

void variable_L_detect (void) {
    //====== Calculate Ii from digital to analog ======//
    if(IiR_fb<0) {
        IiR_fb_ana = -IiR_fb*Ii_D2A;
    } else {
        IiR_fb_ana = IiR_fb*Ii_D2A;
    }

    /*if(IiS_fb<0) {
        IiS_fb_ana = -IiS_fb*Ii_D2A;
    } else {
        IiS_fb_ana = IiS_fb*Ii_D2A;
    }

    if(IiT_fb<0) {
        IiT_fb_ana = -IiT_fb*Ii_D2A;
    } else {
        IiT_fb_ana = IiT_fb*Ii_D2A;
    }*/
    //====== Calculate Ig from digital to analog ======//
    if(IgR_fb<0) {
        IgR_fb_ana = -IgR_fb*Ig_D2A;
    } else {
        IgR_fb_ana = IgR_fb*Ig_D2A;
    }

    /*if(IgS_fb<0) {
        IgS_fb_ana = -IgS_fb*Ig_D2A;
    } else {
        IgS_fb_ana = IgS_fb*Ig_D2A;
    }

    if(IgT_fb<0) {
        IgT_fb_ana = -IgT_fb*Ig_D2A;
    } else {
        IgT_fb_ana = IgT_fb*Ig_D2A;
    }*/

    if(IiR_fb_ana>40) {         //01-Nov-2019 22:16:19
        IiR_fb_ana=40;
    }
    /*if(IiS_fb_ana>40) {
        IiS_fb_ana=40;
    }
    if(IiT_fb_ana>40) {
        IiT_fb_ana=40;
    }*/
    if(IgR_fb_ana>40) {
        IgR_fb_ana=40;
    }
    /*if(IgS_fb_ana>40) {
        IgS_fb_ana=40;
    }
    if(IgT_fb_ana>40) {
        IgT_fb_ana=40;
    }*/

    //====== Inductance ============================//
    L_iR_attenu  = L_table_Iin[IiR_fb_ana];
    //L_iS_attenu  = L_table_Iin[IiS_fb_ana];
    //L_iT_attenu  = L_table_Iin[IiT_fb_ana];

    L_gR_attenu  = L_table_Ign[IgR_fb_ana];
    //L_gS_attenu  = L_table_Ign[IgS_fb_ana];
    //L_gT_attenu  = L_table_Ign[IgT_fb_ana];


}

void voltage_current_reference(void) {
    /*if(hiZCIiRsaved == 0){
         IiR_fb = -IiR_fb;
     }else{
         IiR_fb = IiR_fb;
     }
     if(hiZCIiSsaved == 0){
         IiS_fb = -IiS_fb-5;
     }else{
         IiS_fb = IiS_fb-5;
     }
     if(hiZCIiTsaved == 0){
         IiT_fb = -IiT_fb-10;
     }else{
         IiT_fb = IiT_fb-10;
     }
     if(hiZCIgRsaved == 0){
         IgR_fb = -IgR_fb-10;
     }else{
         IgR_fb = IgR_fb-10;
     }
     if(hiZCIgSsaved == 0){
         IgS_fb = -IgS_fb-5;
     }else{
         IgS_fb = IgS_fb-5;
     }
     if(hiZCIgTsaved == 0){
         IgT_fb = -IgT_fb;
     }else{
         IgT_fb = IgT_fb;
     }*/

   if(hiZCVCRsaved == 0) {
        VCR_fb = (-VCR_fb-13.5)*0.988634;
    } else {
        VCR_fb = (VCR_fb-13.5)*0.988634;
    }
    /*if(hiZCVCSsaved == 0) {
        VCS_fb = -VCS_fb*0.996272;
    } else {
        VCS_fb = VCS_fb*0.996272;
    }
    if(hiZCVCTsaved == 0) {
        VCT_fb = -VCT_fb*0.9996684;
    } else {
        VCT_fb = VCT_fb*0.9996684;
    }*/
    if(hiZCVPRsaved == 0) {
        VPR_fb = -VPR_fb;
    } else {
        VPR_fb = VPR_fb;
    }
    /*if(hiZCVPSsaved == 0) {
        VPS_fb = -VPS_fb;
    } else {
        VPS_fb = VPS_fb;
    }
    if(hiZCVPTsaved == 0) {
        VPT_fb = -VPT_fb;
    } else {
        VPT_fb = VPT_fb;
    }*/
    if(hiZCIDCsaved == 0) {
        IDC_fb = -IDC_fb;
    } else {
        IDC_fb = IDC_fb;
    }
    
}


void Iref1_calculation(void) {

    //======= current limitation =====//
    if ( Kload > rated_power ) {
        Kload = rated_power ;
    }
    if ( Kload < 0 ) {
        Kload = 0   ;
    }
    //======= Current referance(n) =========//

    IiR_ref1 =sine_V_table[GC_counter_Rn1] * V2A_ratio *Kload;
    //IiS_ref1 =sine_V_table[GC_counter_Sn1] * V2A_ratio *Kload;
    //IiT_ref1=-IiR_ref1 - IiS_ref1 ;
}

void Iref_calculation(void) {
    //=========(n+2)ref========//
    Grid_counter_range();
    variable_L_detect();
    //======= current limitation =====//
    if ( Kload > rated_power ) {
        Kload = rated_power ;
    }
    if ( Kload < 0 ) {
        Kload = 0   ;
    }
    //======= Current referance(n+1) =========//

    IiR_ref1 =sine_V_table[GC_counter_Rn1] * V2A_ratio *Kload;
    IiS_ref1 =sine_V_table[GC_counter_Sn1] * V2A_ratio *Kload;
    IiT_ref1 =-IiR_ref1 - IiS_ref1 ;
}


void duty_calculation(void) {
    IiR_fbD = IiR_fb;
    //IiS_fbD = IiS_fb;
    //IiT_fbD = IiT_fb;
    IgR_fbD = IgR_fb;
    //IgS_fbD = IgS_fb;
    //IgT_fbD = IgT_fb;
    IiR_fb_1D = IiR_fb_1;
    //IiS_fb_1D = IiS_fb_1;
    //IiT_fb_1D = IiT_fb_1;
    IgR_fb_1D = IgR_fb_1;
    //IgS_fb_1D = IgS_fb_1;
    //IgT_fb_1D = IgT_fb_1;


    delta_IiR = IiR_ref1 - IiR_fbD;
    //delta_IiS = IiS_ref1 - IiS_fbD;
    //delta_IiT = IiT_ref1 - IiT_fbD;

    delta_IiR_term = (Li_factor * L_iR_attenu );
    //delta_IiS_term = (Li_factor * L_iS_attenu );
    //delta_IiT_term = (Li_factor * L_iT_attenu );
/*
    CompGainR_Ii = CompConst_Ii * L_gR_attenu ;
    CompGainS_Ii = CompConst_Ii * L_gS_attenu ;
    CompGainT_Ii = CompConst_Ii * L_gT_attenu ;

    CompGainR_Ig = CompConst_Ig * L_gR_attenu ;
    CompGainS_Ig = CompConst_Ig * L_gS_attenu ;
    CompGainT_Ig = CompConst_Ig * L_gT_attenu ;
*/
    VAC_R_term = VCR_fb * VAC_Const;
    //VAC_S_term = VCS_fb * VAC_Const;
    //VAC_T_term = VCT_fb * VAC_Const;
/*
    IiCompR = (delta_IiR - IiR_fbD + IiR_fb_1D)* CompGainR_Ii;
    IiCompS = (delta_IiS - IiS_fbD + IiS_fb_1D)* CompGainS_Ii;
    IiCompT = (delta_IiT - IiT_fbD + IiT_fb_1D)* CompGainT_Ii;

    IgCompR = (IgR_fbD - IgR_fb_1D)* CompGainR_Ig;
    IgCompS = (IgS_fbD - IgS_fb_1D)* CompGainS_Ig;
    IgCompT = (IgT_fbD - IgT_fb_1D)* CompGainT_Ig;
*/
    swduty_R = 302-(delta_IiR * delta_IiR_term)  - VAC_R_term;
    swduty_S = 302-(delta_IiS * delta_IiS_term)  - VAC_S_term;
    swduty_T = 302-(delta_IiT * delta_IiT_term)  - VAC_T_term;

    //600 can be adjusted
/*
    SVPWM_Max = swduty_R;
    SVPWM_Min = swduty_R;
    if(swduty_S>SVPWM_Max) {
        SVPWM_Max = swduty_S;
    }
    if(swduty_T>SVPWM_Max) {
        SVPWM_Max = swduty_T;
    }

    if(swduty_S<SVPWM_Min) {
        SVPWM_Min = swduty_S;
    }
    if(swduty_T<SVPWM_Min) {
        SVPWM_Min = swduty_T;
    }

    SVPWM =302-((SVPWM_Max + SVPWM_Min)>>1);//first vaule must to set (GTPR/2)
    swduty_R = swduty_R + SVPWM;
    swduty_S = swduty_S + SVPWM;
    swduty_T = swduty_T + SVPWM;
*/
    //----------------------------  duty limitation ------------------------------------//

    if(swduty_R > duty_max ) {
        swduty_R = duty_max ;
    } else if( swduty_R < duty_min) {
        swduty_R = duty_min ;
    }
    if(swduty_S > duty_max ) {
        swduty_S = duty_max ;
    } else if( swduty_S < duty_min) {
        swduty_S = duty_min ;
    }
    if(swduty_T > duty_max ) {
        swduty_T = duty_max ;
    } else if( swduty_T < duty_min) {
        swduty_T = duty_min ;
    }

    duty_RH = swduty_R + deadtime;
    duty_RL = swduty_R - deadtime;
    duty_SH = swduty_S + deadtime;
    duty_SL = swduty_S - deadtime;
    //duty_TH = swduty_T + deadtime;
    //duty_TL = swduty_T - deadtime;

    IiR_fb_1 = IiR_fb;
    //IiS_fb_1 = IiS_fb;
    //IiT_fb_1 = IiT_fb;
    IgR_fb_1 = IgR_fb;
    //IgS_fb_1 = IgS_fb;
    //IgT_fb_1 = IgT_fb;
    
    //LED2=0;

}



void over_detect(void) {                                 //20190131 edit

    hw_detection();
    
    if( IiR_fb > over_Iin || IiR_fb < -over_Iin) {
        wIiR_error ++;
        if ( wIiR_error >= 2) {
            wIiR_error = 0;
            LED.FAULT = 9 ;
            protection();
            return;
        }
    } else {
        wIiR_error = 0;
    }

    if( IiS_fb > over_Iin || IiS_fb < -over_Iin) {
        wIiS_error ++;
        if ( wIiS_error >= 2) {
            wIiS_error = 0;
            LED.FAULT = 10 ;
            protection();
            return;
        }
    } else {
        wIiS_error = 0;
    }

    if( IiT_fb > over_Iin || IiT_fb < -over_Iin) {
        wIiT_error ++;
        if ( wIiT_error >= 2) {
            wIiT_error = 0;
            LED.FAULT = 11 ;
            protection();
            return;
        }
    } else {
        wIiT_error = 0;
    }

    if( IgR_fb > over_Ign || IgR_fb < -over_Ign) {
        wIgR_error ++;
        if ( wIgR_error >= 2) {
            wIgR_error = 0;
            LED.FAULT = 12 ;
            protection();
            return;
        }
    } else {
        wIgR_error = 0;
    }

    if( IgS_fb > over_Ign || IgS_fb < -over_Ign) {
        wIgS_error ++;
        if ( wIgS_error >= 2) {
            wIgS_error = 0;
            LED.FAULT = 13 ;
            protection();
            return;
        }
    } else {
        wIgS_error = 0;
    }

    if( IgT_fb > over_Ign || IgT_fb < -over_Ign) {
        wIgT_error ++;
        if ( wIgT_error >= 2) {
            wIgT_error = 0;
            LED.FAULT = 14 ;
            protection();
            return;
        }
    } else {
        wIgT_error = 0;
    }

    if( IDC_fb > over_IDC || IDC_fb < -over_IDC ) {
        wIDC_error ++;
        if (  wIDC_error >= 4) {
            wIDC_error = 0;
            LED.FAULT = 17;
            protection();
            return;
        }
    } else {
        wIDC_error = 0;
    }

    if(FVDC_fb < FVDC_min ) {
        wFVDC_error ++;
        if(wFVDC_error >= 4) {
            wFVDC_error = 0;
            LED.FAULT = 1 ;
            protection();
            return;
        }
    } else {
        wFVDC_error = 0 ;
    }

    if( FVDC_fb > FVDC_max) {
        wFVDC1_error ++;
        if(wFVDC1_error >= 4) {
            wFVDC1_error = 0;
            LED.FAULT = 2 ;
            protection();
            return;
        }
    } else {
        wFVDC1_error = 0 ;
    }


    if( VPR_fb > over_VPn||VPR_fb < -over_VPn) {
        wVPR_error ++;
        if (wVPR_error >= 4) {
            wVPR_error = 0;
            LED.FAULT = 3 ;
            protection();
            return;
        }
    } else {
        wVPR_error = 0;
    }

    if( VPS_fb > over_VPn|| VPS_fb < -over_VPn) {
        wVPS_error ++;
        if (wVPS_error >= 4) {
            wVPS_error = 0;
            LED.FAULT = 4 ;
            protection();
            return;
        }
    } else {
        wVPS_error = 0;
    }

    if( VPT_fb > over_VPn || VPT_fb < -over_VPn) {
        wVPT_error ++;
        if (wVPT_error >= 4) {
            wVPT_error = 0;
            LED.FAULT = 5 ;
            protection();
            return;
        }
    } else {
        wVPT_error = 0;
    }

    if( VCR_fb > over_VCn || VCR_fb < -over_VCn) {
        wVCR_error ++;
        if ( wVCR_error >= 4) {
            wVCR_error = 0;
            LED.FAULT = 6 ;
            protection();
            return;
        }
    } else {
        wVCR_error = 0;
    }

    if( VCS_fb > over_VCn || VCS_fb < -over_VCn) {
        wVCS_error ++;
        if ( wVCS_error >= 4) {
            wVCS_error = 0;
            LED.FAULT = 7 ;
            protection();
            return;
        }
    } else {
        wVCS_error = 0;
    }

    if( VCT_fb > over_VCn ||  VCT_fb < -over_VCn) {
        wVCT_error ++;
        if ( wVCT_error >= 4) {
            wVCT_error = 0;
            LED.FAULT = 8 ;
            protection();
            return;
        }
    } else {
        wVCT_error = 0;
    }

    if(Emergency == 1) {
        wEmer_error ++;
        if( wEmer_error >= 4) {
            wEmer_error = 0;
            LED.FAULT = 15 ;
            protection();
            return;
        }
    } else {
        wEmer_error = 0;
    }

    if(powergood == 0) {
        wPow_error ++;
        if( wPow_error >= 4) {
            wPow_error = 0;
            LED.FAULT = 16 ;
            protection();
            return;
        }
    } else {
        wPow_error = 0;
    }

    if( tempR_fb > over_temp ) {
        wTempR_error ++;
        if ( wTempR_error >= 4) {
            wTempR_error = 0;
            LED.FAULT = 19 ;
            protection();
            return;
        }
    } else {
        wTempR_error = 0;
    }

    if( tempS_fb > over_temp ) {
        wTempS_error ++;
        if ( wTempS_error >= 4) {
            wTempS_error = 0;
            LED.FAULT = 20 ;
            protection();
            return;
        }
    } else {
        wTempS_error = 0;
    }

    if( tempT_fb > over_temp ) {
        wTempT_error ++;
        if ( wTempT_error >= 4) {
            wTempT_error = 0;
            LED.FAULT = 21 ;
            protection();
            return;
        }
    } else {
        wTempT_error = 0;
    }

    if (VacR_protectionCheck == 1) {
        if(hiZCVCRsaved == 0) {
            VPR_pro = -VPR_pro;
        } else {
            VPR_pro = VPR_pro;
        }
        VPR_proerror = VPR_pro-sine_V_table[ UPS_counter_Rn];

        if (VPR_proerror>=800 || VPR_proerror<=-800) {
            LED.FAULT = 18;
            protection();
            return;
        }
    }


}

void Preover_detect(void) {                                 //20190131 edit

    hw_detection();
   
    if( IiR_fb > Preover_Iin || IiR_fb < -Preover_Iin) {
        wIiR_error ++;
        if ( wIiR_error >= 1) {
            wIiR_error = 0;
            LED.FAULT = 9 ;
            protection();
            return;
        }
    } else {
        wIiR_error = 0;
    }

    if( IiS_fb > Preover_Iin || IiS_fb < -Preover_Iin) {
        wIiS_error ++;
        if ( wIiS_error >= 1) {
            wIiS_error = 0;
            LED.FAULT = 10 ;
            protection();
            return;
        }
    } else {
        wIiS_error = 0;
    }

    if( IiT_fb > Preover_Iin || IiT_fb < -Preover_Iin) {
        wIiT_error ++;
        if ( wIiT_error >= 1) {
            wIiT_error = 0;
            LED.FAULT = 11 ;
            protection();
            return;
        }
    } else {
        wIiT_error = 0;
    }

    if( IgR_fb > Preover_Ign || IgR_fb < -Preover_Ign) {
        wIgR_error ++;
        if ( wIgR_error >= 1) {
            wIgR_error = 0;
            LED.FAULT = 12 ;
            protection();
            return;
        }
    } else {
        wIgR_error = 0;
    }

    if( IgS_fb > Preover_Ign || IgS_fb < -Preover_Ign) {
        wIgS_error ++;
        if ( wIgS_error >= 1) {
            wIgS_error = 0;
            LED.FAULT = 13 ;
            protection();
            return;
        }
    } else {
        wIgS_error = 0;
    }

    if( IgT_fb > Preover_Ign || IgT_fb < -Preover_Ign) {
        wIgT_error ++;
        if ( wIgT_error >= 1) {
            wIgT_error = 0;
            LED.FAULT = 14 ;
            protection();
            return;
        }
    } else {
        wIgT_error = 0;
    }

    if( IDC_fb > Preover_IDC || IDC_fb < -Preover_IDC ) {
        wIDC_error ++;
        if (  wIDC_error >= 1) {
            wIDC_error = 0;
            LED.FAULT = 17;
            protection();
            return;
        }
    } else {
        wIDC_error = 0;
    }    

    if( tempR_fb > over_temp ) {
        wTempR_error ++;
        if ( wTempR_error >= 4) {
            wTempR_error = 0;
            LED.FAULT = 19 ;
            protection();
            return;
        }
    } else {
        wTempR_error = 0;
    }

    if( tempS_fb > over_temp ) {
        wTempS_error ++;
        if ( wTempS_error >= 4) {
            wTempS_error = 0;
            LED.FAULT = 20 ;
            protection();
            return;
        }
    } else {
        wTempS_error = 0;
    }

    if( tempT_fb > over_temp ) {
        wTempT_error ++;
        if ( wTempT_error >= 4) {
            wTempT_error = 0;
            LED.FAULT = 21 ;
            protection();
            return;
        }
    } else {
        wTempT_error = 0;
    }

    if( FVDC_fb > FVDC_max) {
        wFVDC1_error ++;
        if(wFVDC1_error >= 4) {
            wFVDC1_error = 0;
            LED.FAULT = 2 ;
            protection();
            return;
        }
    } else {
        wFVDC1_error = 0 ;
    }    

    if(Emergency == 1) {
        wEmer_error ++;
        if( wEmer_error >= 4) {
            wEmer_error = 0;
            LED.FAULT = 15 ;
            protection();
            return;
        }
    } else {
        wEmer_error = 0;
    }

}



void hw_detection(void) {                                  //20190131 edit
    if (Hardware_protection_M==1 ) {
        HPMdebounce= 1 ;
        for(swcounter=0; swcounter < 15 ; swcounter++) {
            HPMdebounce &= Hardware_protection_M ;
        }
        if(HPMdebounce == 1) {
            HPM_protect++;
        } else {
            HPM_protect = 0;
        }
    }
    if(HPM_protect >= 2) {
        HPM_protect = 3 ;
        Hardware_portection=1;
        protection();
    }
}


void protection(void) {                   //20190131 edit
    PWMRH_IO = 0 ;    // low output
    PWMRH_EN = 0 ;    // disable output
    PWMSH_IO = 0 ;
    PWMSH_EN = 0 ;
    PWMTH_IO = 0 ;
    PWMTH_EN = 0 ;
    PWMRL_IO = 0 ;
    PWMRL_EN = 0 ;
    PWMSL_IO = 0 ;
    PWMSL_EN = 0 ;
    PWMTL_IO = 0 ;
    PWMTL_EN = 0 ;
    Relay= 0 ;            //low output
    GPT.GTSTR.WORD = 0X0000; //count opereation is stopped
    IEN(PERIB, INTB128) = 0;  // disable the interrupt
    IEN(PERIB, INTB129) = 0;  // disable the interrupt
    IEN(PERIA, INTA210) = 0;
    IR(PERIB, INTB128) = 0;
    IR(PERIB, INTB129) = 0;
    PWMNH_IO = 0 ;
    PWMNH_EN = 0 ;
    PWMNL_IO = 0 ;
    PWMNL_EN = 0 ;

    protection_on = 1 ;
}

void setting_PWM_IO(void) {
    GPT0.GTIOR.BIT.GTIOA = 0x07;  // RH 010
    GPT0.GTIOR.BIT.GTIOB = 0x1B;  // RL 101
    GPT1.GTIOR.BIT.GTIOA = 0x07;  // SH 010
    GPT1.GTIOR.BIT.GTIOB = 0x1B;  // SL 101
    GPT2.GTIOR.BIT.GTIOA = 0x07;  // TH 010
    GPT2.GTIOR.BIT.GTIOB = 0x1B;  // TL 101

    // Pin Output Enable
    PWMRH_EN = 1;
    PWMSH_EN = 1;
    PWMTH_EN = 1;
    PWMRL_EN = 1;
    PWMSL_EN = 1;
    PWMTL_EN = 1;
}


void finish_PWM(void) {
    PWMRH_IO = 0 ;    // low output
    PWMRH_EN = 0 ;    // disable output
    PWMSH_IO = 0 ;
    PWMSH_EN = 0 ;
    PWMTH_IO = 0 ;
    PWMTH_EN = 0 ;
    PWMRL_IO = 0 ;
    PWMRL_EN = 0 ;
    PWMSL_IO = 0 ;
    PWMSL_EN = 0 ;
    PWMTL_IO = 0 ;
    PWMTL_EN = 0 ;
    Relay= 0 ;

    GPT.GTSTR.WORD = 0X0000; //count opereation is stopped
    IEN(PERIB, INTB128) = 0;  // disable the interrupt
    IEN(PERIB, INTB129) = 0;  // disable the interrupt
    IEN(PERIA, INTA210) = 0;
    IR(PERIB, INTB128) = 0;
    IR(PERIB, INTB129) = 0;
    PWMNH_IO = 0 ;
    PWMNH_EN = 0 ;
    PWMNL_IO = 0 ;
    PWMNL_EN = 0 ;
    LED.FAULT=31;
}

void LED_display(void) {
    LEDFault1 = LED.F1 ;
    LEDFault2 = LED.F2 ;
    LEDFault3 = LED.F3 ;
    LEDFault4 = LED.F4 ;
    LEDFault5 = LED.F5 ;
}

void LEDScope(void) {
 /*   bbLED.scope =  IiR_ref1;
    
    LED3 = ~LED3;
    LED4 = bbLED.F1;
    LED3 = ~LED3;
    LED4 = bbLED.F2;
    LED3 = ~LED3;
    LED4 = bbLED.F3;
    LED3 = ~LED3;
    LED4 = bbLED.F4;
    LED3 = ~LED3;
    LED4 = bbLED.F5;
    LED3 = ~LED3;
    LED4 = bbLED.F6;
    LED3 = ~LED3;
    LED4 = bbLED.F7;
    LED3 = ~LED3;
    LED4 = bbLED.F8;
    LED3 = ~LED3;
    LED4 = bbLED.F9;
    LED3 = ~LED3;
    LED4 = bbLED.F10;
    LED3 = ~LED3;
    LED4 = bbLED.F11;
    LED3 = ~LED3;
    LED4 = bbLED.F12;
    LED3 = ~LED3;
    LED4 = bbLED.F13;
    LED3 = ~LED3;
    LED4 = bbLED.F14;
    LED3 = ~LED3;
    LED4 = bbLED.F15;
    LED3 = ~LED3;
    LED4 = bbLED.F16;
    LED3 = ~LED3;
    LED3=LED3;LED3=LED3;LED3=LED3;LED3=LED3;LED3=LED3;
    
    bbLED.scope =  IiS_ref1;    
    LED3 = ~LED3;
    LED4 = bbLED.F1;
    LED3 = ~LED3;
    LED4 = bbLED.F2;
    LED3 = ~LED3;
    LED4 = bbLED.F3;
    LED3 = ~LED3;
    LED4 = bbLED.F4;
    LED3 = ~LED3;
    LED4 = bbLED.F5;
    LED3 = ~LED3;
    LED4 = bbLED.F6;
    LED3 = ~LED3;
    LED4 = bbLED.F7;
    LED3 = ~LED3;
    LED4 = bbLED.F8;
    LED3 = ~LED3;
    LED4 = bbLED.F9;
    LED3 = ~LED3;
    LED4 = bbLED.F10;
    LED3 = ~LED3;
    LED4 = bbLED.F11;
    LED3 = ~LED3;
    LED4 = bbLED.F12;
    LED3 = ~LED3;
    LED4 = bbLED.F13;
    LED3 = ~LED3;
    LED4 = bbLED.F14;
    LED3 = ~LED3;
    LED4 = bbLED.F15;
    LED3 = ~LED3;
    LED4 = bbLED.F16;
    LED3 = ~LED3;

 /*   LED3 = ~LED3; LED3 = LED3;
    LED4 = bbLED.F1; LED4 = bbLED.F1;
    LED3 = ~LED3; LED3 = LED3;
    LED4 = bbLED.F2; LED4 = bbLED.F2;
    LED3 = ~LED3; LED3 = LED3;
    LED4 = bbLED.F3; LED4 = bbLED.F3;
    LED3 = ~LED3; LED3 = LED3;
    LED4 = bbLED.F4; LED4 = bbLED.F4;
    LED3 = ~LED3; LED3 = LED3;
    LED4 = bbLED.F5; LED4 = bbLED.F5;
    LED3 = ~LED3; LED3 = LED3;
    LED4 = bbLED.F6; LED4 = bbLED.F6;
    LED3 = ~LED3; LED3 = LED3;
    LED4 = bbLED.F7; LED4 = bbLED.F7;
    LED3 = ~LED3; LED3 = LED3;
    LED4 = bbLED.F8; LED4 = bbLED.F8;
    LED3 = ~LED3; LED3 = LED3;
    LED4 = bbLED.F9; LED4 = bbLED.F9;
    LED3 = ~LED3; LED3 = LED3;
    LED4 = bbLED.F10;LED4 = bbLED.F10;
    LED3 = ~LED3; LED3 = LED3;
    LED4 = bbLED.F11;LED4 = bbLED.F11;
    LED3 = ~LED3; LED3 = LED3;
    LED4 = bbLED.F12;LED4 = bbLED.F12;
    LED3 = ~LED3; LED3 = LED3;
    LED4 = bbLED.F13;LED4 = bbLED.F13;
    LED3 = ~LED3; LED3 = LED3;
    LED4 = bbLED.F14;LED4 = bbLED.F14;
    LED3 = ~LED3; LED3 = LED3;
    LED4 = bbLED.F15;LED4 = bbLED.F15;
    LED3 = ~LED3; LED3 = LED3;
    LED4 = bbLED.F16;LED4 = bbLED.F16;
    LED3 = ~LED3; LED3 = LED3;*/
 }
#ifdef __cplusplus
void abort(void) {

}
#endif
