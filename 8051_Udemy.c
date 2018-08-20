
// lcd pinout settings
sbit LCD_RS at P2_0_bit;
sbit LCD_EN at P2_1_bit;
sbit LCD_D7 at P2_5_bit;
sbit LCD_D6 at P2_4_bit;
sbit LCD_D5 at P2_3_bit;
sbit LCD_D4 at P2_2_bit;

//Gerar uma onda quadrada com duty cycle de 50%
void squareWave(void){
     while(1){
        while(!TCON.TF0);
        TCON.TF0 = 0;
        P3.B7 = 1;
        while(!TCON.TF0);
        TCON.TF0 = 0;
        P3.B7 = 0;
     }
}
//Gerar uma onda quadrada com duty cycle de 25%
void wave_25_duty(void){
     while(1){
       //********* 150us ******//
        TL0 = 0x76;                              // Lower Byte
        TH0 = 0xff;                              // Upper Byte
        TCON.TR0 = 1;
        //********************//
        P3.B7 = 0;
        while(!TCON.TF0);
        TCON.TR0 = 0;
        TCON.TF0 = 0;
        //********* 50us ******//
        TL0 = 0xD2;                              // Lower Byte
        TH0 = 0xff;                              // Upper Byte
        TCON.TR0 = 1;                            // Run timer
        //********************//
        P3.B7 = 1;
        while(!TCON.TF0);
        TCON.TR0 = 0;
        TCON.TF0 = 0;
     }
  }

/*             Função de Interrupção de Hadware externo
               A interupção atua na BORDA de DESCIDA (de 1 para 0)
  
  IE = 0x85 ---> Habilita as Duas interrupções externas (INT0 e INT1)
  Registrador IE = EA-XX-ET2-ES-ET1-EX1-ET0-EX0
  1000-0001 --->   1 -0 - 0 -0 - 0 - 1 - 0 - 1
  EA = 1
  EX1 = 1
  EX0 = 1
*/
char toggle = 0;
char counter2 = 0;

/*--------Interrupção  INT1 --------*/
void Ex1ISR() iv IVT_ADDR_EX1 ilevel 0 ics ICS_AUTO {
     counter2++;
}

/*--------Interrupção  INT0 --------*/
void Ex0ISR() iv IVT_ADDR_EX0 ilevel 0 ics ICS_AUTO {
     toggle =! toggle;                            // Altenar os Input-Output do Port-P1
     if(toggle)
        P1 = 0x00;                                // 0000-0000
     else
        P1 = 0xff;                                // 1111-1111
}
void main() {

     unsigned int sum;
     unsigned char counter;
     char txt[6];
    
     P0 = 0xff;                                   // 1111-1111  PORT1 (1-Input)
     P1 = 0x00;

     TMOD = 0x26;                                 // 0010-0110 Counter, mode 2(auto reload), timer0

     PCON |= 0x80;                                // Set SMOD
     SCON  = 0x50;                                // 8-bit, rx habilitado
     TL1   = 0x00;                                // Byte menos significativo
     TH1   = 0xFD;                                // Byte mais significativo
     TCON.TR1 = 1;                                // Run timer
     

     TH0 = 0;
     TL0 = 0;
     TCON.TF0 = 0;
     TCON.TR0 = 1;

     Lcd_init();
     delay_ms(10);
     lcd_cmd(_LCD_CURSOR_OFF);                    // lcd_cmd() ---> função para fazer comandos no LCD
     lcd_out(1,1,"Counter=");

     IE = 0x85;                                   // 1000-0101 ---> Habilitar interrupção externa
     TCON.IT0 = 1;                                // IT0 = 1 (Habilita a entrada do sinal para interrupção 0)
     TCON.IT1 = 1;                                // Habilita a Segunda Interrupção

     while(1){
        counter = TL0;
        ByteToStr(counter, txt);
        lcd_out(2,1,txt);
        UART1_WRITE_TEXT("Contador de pulso =");
        UART1_WRITE_TEXT(txt);
        UART1_WRITE_TEXT("\r\n");
        
        ByteToStr(counter2, txt);
        UART1_WRITE_TEXT("Counter2=");
        UART1_WRITE_TEXT(txt);
        UART1_WRITE_TEXT("\r\n");
        delay_ms(500);
     }
     
    UART1_WRITE_TEXT("UsandoUART");
     
     while(1){
         sum = P0 + P1;
         wordToStr(sum, txt);                     // Converte a palavra para uma string
         lcd_out(2,1,"P0+P1=");
         lcd_out(2,7,txt);
         UART1_WRITE_TEXT("P0+P1=");
         UART1_WRITE_TEXT(txt);
         UART1_WRITE_TEXT("\r\n");
         delay_ms(500);
     }
}