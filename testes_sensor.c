#include <testes_sensor.h>
#include <LCD.C>

// Entradas: Sensores Ultrassônicos
#define ECHO_R             pin_c2 //17
#define ECHO_A             pin_c3 //18

// Saídas: Sensores Ultrassônicos
#define TRIGGER_R          pin_d3 //22
#define TRIGGER_A          pin_c4 //23



float sensorUltrassonico (int enabl, int sensor1ou2)
{
   int16 time;             
   float distancia;        
   
  
   if (sensor1ou2 == 1) //sensor água
   {
                  if(enabl == 1)
                  {
                     //habilitar sensor
                  
                     setup_timer_0(RTCC_INTERNAL|RTCC_DIV_16);      
                                                          
                     // Dispara um pulso de 10us para enviar a onda ultrassonica
                     output_high(TRIGGER_A);
                     delay_us(10);
                     output_low(TRIGGER_A);
                      
                     // Aguarda o retorno da onda do ultrassom e calcula o tempo de retorno
                     while(!input(ECHO_A))
                     {  }
                     set_timer0(0);
                     while(input(ECHO_A))
                     {  }
                     time = get_timer0();
                     distancia = 16 * time * 0.017;
                     delay_ms(1000);
                     set_timer0(0);
                     return distancia;
                     
                  }
                  
                  else
                  {
                     output_low(TRIGGER_A);
                  }
                   
                  
                   
   }
   
   else if(sensor1ou2 == 2) //sensor ração
   {
   
                  if(enabl == 1)
                  {
                     //habilitar sensor
                  
                     setup_timer_0(RTCC_INTERNAL|RTCC_DIV_16);      
                                                          
                     // Dispara um pulso de 10us para enviar a onda ultrassonica
                     output_high(TRIGGER_R);
                     delay_us(10);
                     output_low(TRIGGER_R);
                      
                     // Aguarda o retorno da onda do ultrassom e calcula o tempo de retorno
                     while(!input(ECHO_R))
                     {  }
                     set_timer0(0);
                     while(input(ECHO_R))
                     {  }
                     time = get_timer0();
                     distancia = 16 * time * 0.017;
                     delay_ms(1000);
                     set_timer0(0);
                     return distancia;
                     
                  }
                  
                  else
                  {
                     output_low(TRIGGER_R);
                  }                    
   }  
 }


void main()
{
lcd_init();
int i;
float dist;
float dista;
   while(TRUE)
   {       
            dist = 0;
            dista = 0;
            for(i=0; i < 5; i++)
               dist += sensorUltrassonico(1,1);
            dist = dist/5.0;
               
            lcd_gotoxy(1,1);
            printf(LCD_PUTC, "Distancia: %2f", dist);
      
              
            /*for(i=0; i < 3; i++)
               dista += sensorUltrassonico(1,2)/3.0;
               
            lcd_gotoxy(1, 2);
            printf(LCD_PUTC, "Distancia: %2f", dista);
            
            delay_ms(500);
            *
            
        /*    
 lcd_putc('\f');
            lcd_gotoxy(4, 1);           // Go to column 4 row 1
            lcd_putc("PIC16F877A");
            lcd_gotoxy(4, 2);           // Go to column 4 row 2
            lcd_putc("LCD example");
*/
    }

}
