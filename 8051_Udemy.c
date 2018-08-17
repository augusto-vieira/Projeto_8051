
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
void main() {

     unsigned int sum;
     char txt[6];
    
     P0 = 0xff;                                   // 1111-1111  PORT1 (1-Input)
     P1 = 0x00;                                   // 0000-0000  PORT2 (0-Output)
     UART1_INIT(9600);
     PCON.SMOD = 0;
     
     TMOD = 0x02;
     SCON = 0x50;                                 // 8-bit, rx enable
     TL0  = 0x00;                                 // Lower Byte
     TH0  = 0xD2;                                 // Upper Byte
     TCON.TR0  = 1;                               // Run timer
     squareWave();
     
     Lcd_init();
     delay_ms(10);
     lcd_cmd(_LCD_CURSOR_OFF);                    // lcd_cmd() ---> função para fazer comandos no LCD
     lcd_out(1,1,"****************");
     UART1_WRITE_TEXT("Usando o UART");
     
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