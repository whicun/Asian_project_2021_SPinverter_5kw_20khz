/***********************************************************************/
/*                                                                     */
/*  FILE        :hwsetup.h	                                           */
/*  DATE        :Thr, May 10, 2018                                     */
/*  DESCRIPTION :Define mcu interface of RSK                           */
/*  CPU TYPE    :RX62T                                                 */
/*                                                                     */
/*                                                                     */
/***********************************************************************/

#define _HWSETUP_H_
#ifdef _HWSETUP_H_

/*define zero-crossing pin*/
#define Hardware_protection_M     PORTA.PIDR.BIT.B6

/*define LED display I/O date*/
#define power_on                             PORT1.PODR.BIT.B4
#define hoVDC                                   PORT1.PODR.BIT.B3
#define hoVAC_ok                              PORT1.PODR.BIT.B2
#define problem                                PORTC.PODR.BIT.B6 //(Problem)
#define Hardware_portection         PORTC.PODR.BIT.B5
#define LEDFault1                            PORT8.PODR.BIT.B2
#define LEDFault2                            PORT8.PODR.BIT.B1
#define LEDFault3                            PORT8.PODR.BIT.B0 
#define LEDFault4                            PORTC.PODR.BIT.B4
#define LEDFault5                            PORTC.PODR.BIT.B3
#define hostart_up                          PORT7.PODR.BIT.B7
#define LED1                                      PORT7.PODR.BIT.B6 
#define LED2                                     PORTC.PODR.BIT.B2                           
#define LED3                                     PORT7.PODR.BIT.B5 
#define LED4                                     PORT7.PODR.BIT.B4

/*define Relay & Buffer_in I/O date*/
#define Relay                 PORT2.PODR.BIT.B5  
#define Buffer_in1        PORT2.PODR.BIT.B4
#define Buffer_in2        PORT2.PODR.BIT.B0
#define Buffer_in3        PORT5.PODR.BIT.B6
#define Buffer_in4        PORT5.PODR.BIT.B3
#define Buffer_in5        PORT5.PODR.BIT.B1
#define Buffer_in6        PORTB.PODR.BIT.B6
#define Buffer_in7        PORTB.PODR.BIT.B5

/*define PWM_B series I/O date*/
#define PWMRH_IO            PORT2.PODR.BIT.B3
#define PWMSH_IO            PORT2.PODR.BIT.B2
#define PWMTH_IO            PORT2.PODR.BIT.B1
#define PWMRL_IO            PORT1.PODR.BIT.B7
#define PWMSL_IO            PORT8.PODR.BIT.B7
#define PWMTL_IO            PORT8.PODR.BIT.B6
#define PWMNH_IO            PORTE.PODR.BIT.B7
#define PWMNL_IO            PORTE.PODR.BIT.B6

/*define cycle_sign pin*/
#define ZCVCR                 PORT6.PIDR.BIT.B1
#define ZCVCS                 PORT6.PIDR.BIT.B2
#define ZCVCT                 PORT6.PIDR.BIT.B3
#define ZCVPR                 PORT0.PIDR.BIT.B3
#define ZCVPS                 PORT0.PIDR.BIT.B5
#define ZCVPT                 PORT0.PIDR.BIT.B7           
#define ZCIiR                 PORT3.PIDR.BIT.B3
#define ZCIiS                 PORTJ.PIDR.BIT.B3
#define ZCIiT                 PORTJ.PIDR.BIT.B5
#define ZCIgR                 PORT6.PIDR.BIT.B4  
#define ZCIgS                 PORTE.PIDR.BIT.B0  
#define ZCIgT                 PORTE.PIDR.BIT.B1
#define ZCIDC                 PORTF.PIDR.BIT.B5

/*define protection pin*/
#define powergood         PORT7.PIDR.BIT.B1 
#define Emergency         PORT7.PIDR.BIT.B2

/*define PWM_B series output enable pin*/
#define PWMRH_EN          GPT0.GTONCR.BIT.OAE         
#define PWMSH_EN          GPT1.GTONCR.BIT.OAE
#define PWMTH_EN          GPT2.GTONCR.BIT.OAE
#define PWMRL_EN          GPT0.GTONCR.BIT.OBE
#define PWMSL_EN          GPT1.GTONCR.BIT.OBE
#define PWMTL_EN          GPT2.GTONCR.BIT.OBE
#define PWMNH_EN          GPT3.GTONCR.BIT.OAE
#define PWMNL_EN          GPT3.GTONCR.BIT.OBE

/*define PWM_B series output state for 3 phase PWM*/
#define PWMRH_IOR        GPT0.GTIOR.BIT.GTIOA     
#define PWMSH_IOR        GPT1.GTIOR.BIT.GTIOA 
#define PWMTH_IOR        GPT2.GTIOR.BIT.GTIOA 
#define PWMRL_IOR        GPT0.GTIOR.BIT.GTIOB 
#define PWMSL_IOR        GPT1.GTIOR.BIT.GTIOB 
#define PWMTL_IOR        GPT2.GTIOR.BIT.GTIOB 
#define PWMNH_IOR        GPT3.GTIOR.BIT.GTIOA 
#define PWMNL_IOR        GPT3.GTIOR.BIT.GTIOB 

/*define B_duty compare match register for 3-phase PWM(single buffer)*/
#define duty_RH GPT0.GTCCRC
#define duty_SH GPT1.GTCCRC
#define duty_TH GPT2.GTCCRC
#define duty_RL GPT0.GTCCRE
#define duty_SL GPT1.GTCCRE
#define duty_TL GPT2.GTCCRE
#define duty_NH GPT3.GTCCRC
#define duty_NL GPT3.GTCCRE

//define up and low limit
//24-Sep-2020 15:43:19    760V 3511
#define FVDC_Ini 3507    //757V FVDC_A2D Ratio 4.63266 //24-Sep-2020 15:43:19
#define FVDC_min 3473    //749V FVDC_A2D Ratio 4.63685 //24-Sep-2020 15:43:19
#define FVDC_max 3563    //768V FVDC_A2D Ratio 4.63932 //24-Sep-2020 15:43:19

#define HVDC_Ini 3580    //377V HVDC_A2D Ratio 9.4961 //24-Dec-2021 15:43:19
#define HVDC_min 3513    //370V HVDC_A2D Ratio 9.4961 //24-Dec-2021 15:43:19
#define HVDC_max 3703    //390V HVDC_A2D Ratio 9.4961 //24-Dec-2021 15:43:19


#define over_VPn 3742   //350V Vpn_A2D Ratio 10.69 //24-Sep-2020 15:27:19
#define over_VCn 3742   //350V Vcn_A2D Ratio 10.69 //24-Sep-2020 15:27:19

//when rated_power changed, should change the vaule of current protection 
#define over_Iin 290 //Initial 8A Ii_A2D Ratio 36.22 (45.7A Enter hw_detection ) //24-Sep-2020 14:08:19
#define over_Ign 290 //Initial 8A Ig_A2D Ratio 36.26 (45.7A Enter hw_detection ) //25-Sep-2020 14:08:19

#define over_IDC 613 //Initial 9A IDC_A2D Ratio 61.3 (60.4A Enter hw_detection 3841) //25-Sep-2020 14:08:19

//when voltage precharge, should set the vaule of current protection 
#define Preover_Iin 374 //Initial 20A Ii_A2D Ratio 18.7 (85.1A Enter hw_detection 1712) //24-Sep-2020 14:08:19
#define Preover_Ign 370 //Initial 20A Ig_A2D Ratio 18.5 (85.1A Enter hw_detection 1712) //25-Sep-2020 14:08:19

#define Preover_IDC 797 //Initial 13A IDC_A2D Ratio 61.3 (60.4A Enter hw_detection 3841) //25-Sep-2020 14:08:19

//set the vaule of temperature protection
#define over_temp 3643//when temp=80c Vin=2.83V 2.83*4095/3.3=3643

//define operation mode 
#define AC_detection 1
#define start_up 2


//define counter max value 
#define max_counter 828 

//define grid_detection
#define ZVCR_Counter 10
#define ZVCR_60_min 160//404
#define ZVCR_60_max 165 //424
#define Grid_fre_for_sure 35   //35
#define wait_cycle 250              //be less than (828/2)-(828/6)=278
#define fre_60Hz 1                     // don't set fre_60Hz = 0
#define sequence_min 680
#define sequence_max 700

//define initial counter 
#define ini_R_counter  -1 
#define ini_S_counter 219
#define ini_T_counter 109

#define R_counter1 0
#define S_counter1 220
#define T_counter1 110


//define VDC_ready
#define  VDC_for_sure 1000

//define Ii D2A Ig_D2A //25-Sep-2020 15:27:19
//Ii_A2D = 36.22  Initial (100/1000)*(1.21/1)*(499/2000)*(4095/3.3)=37.4624  //25-Sep-2020 15:27:19
#define Ii_D2A 0.02761  //Initial(1/Ii_A2D) //22-Nov-2019 15:27:19
//Ig_A2D = 36.26  Initial (100/1000)*(1.21/1)*(499/2000)*(4095/3.3)=37.4624  //25-Sep-2020 15:27:19
#define Ig_D2A  0.02758 
#define Li_factor  1.4780         //Initial(1350uH)/380/2*19800/Ii_A2D*3030  //25-Sep-2020 15:27:19
#define CompConst_Ii 0.3378    //Initial(470uH)/380/2*19800/Ii_A2D*3030 //25-Sep-2020 15:27:19
#define CompConst_Ig 0.3415    //Initial(470uH)/380/2*19800/Ig_A2D*3030  //25-Sep-2020 15:27:19
//Vcn_A2D Ratio 10.69 //24-Sep-2020 15:27:19
#define  VAC_Const  0.07434      // Initial(1/380)/2*(1/Vcn_A2D)*3030     //24-Sep-2020 15:27:19

// define duty min & max 
#define duty_max 583		  
#define duty_min 20
#define deadtime 15                   // this value should be set by situation


//define sin_table ratio
#define V2A_ratio  0.0350022    //current rating 500w 25-Sep-2020 15:27:19

//define Grid_mode_power 
#define start_counter 110 //start feeding power to grid 


//define phase shift
#define PF_normal    0
#define PF_leading  1
#define PF_lagging  2



#endif

