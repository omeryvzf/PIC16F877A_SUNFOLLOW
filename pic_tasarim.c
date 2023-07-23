#include <16f877A.h>
#fuses HS
#use delay(clock=8000000)
#use fast_io(a)
#use fast_io(b)
#use fast_io(c)


unsigned long int okunan;
unsigned long int okunan1;
void main(){
   setup_CCP1(CCP_OFF);
   setup_CCP2(CCP_OFF);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   
   set_tris_a(0b00011111);
   set_tris_b(0b00000000);
   set_tris_c(0b00000000);
   setup_adc(adc_clock_div_4);
   setup_adc_ports(ALL_ANALOG);
   
   
   while(1){
      output_high(pin_b1);
      set_adc_channel(0);
      delay_us(20);
      okunan = read_adc();
      set_adc_channel(1);
      delay_us(20);
      okunan1 = read_adc();
      

      if(okunan>okunan1){
         output_high(pin_c1);
         output_low(pin_c0);
      }
      else if(okunan1>okunan){
         
         output_high(pin_c0);
         output_low(pin_c1);        
      }

      else{
      
         output_low(pin_c0);
         output_low(pin_c1);
      }
   
   }
   
   





}
