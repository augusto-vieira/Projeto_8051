
      /*
       enviamos dados para o LCD no formato ASCII
       Vou ligar o LCD � porta 2
       Mas n�o h� necessidade de configurar P2 como sa�da, isso � feito automaticamente pela fun��o lcd_init()
       Mas n�o h� necessidade de configurar P2 como sa�da, isso � feito automaticamente pela fun��o lcd_init()
       Esta fun��o inicializa o LCD no modo de 4 bits
       A fun��o lcd_cmd() � usada para enviar comandos para o LCD
       Lcd_Out() � a fun��o de biblioteca usada para exibir algumas cadeias na linha e coluna especificadas
      
       Podemos adicionar algum atraso, caso contr�rio, a exibi��o ser� atualizada em alta frequ�ncia
       Acrescentei 500 milissegundos de atraso para que a exibi��o seja atualizada duas vezes por segundo.
       
     */
// lcd pinout settings
sbit LCD_RS at P2_0_bit;
sbit LCD_EN at P2_1_bit;
sbit LCD_D7 at P2_5_bit;
sbit LCD_D6 at P2_4_bit;
sbit LCD_D5 at P2_3_bit;
sbit LCD_D4 at P2_2_bit;


void main() {

     unsigned int sum;                            // declarando 2 vari�veis
     char txt[6];
    
     P0 = 0xff;                                   // 1111-1111  PORT1 (1-Input)
     P1 = 0x00;                                   // 0000-0000  PORT2 (0-Output)
     
     Lcd_init();
     delay_ms(10);
     lcd_cmd(_LCD_CURSOR_OFF);                    // lcd_cmd() ---> fun��o para fazer comandos no LCD
     lcd_out(1,1,"****************");
     
     
     while(1){
         sum = P0 + P1;                           // Soma o Port0 com Port1;
         wordToStr(sum, txt);                     // Converte a palavra para uma string
         lcd_out(2,1,"P0+P1=");                   // Vamos converter nosso resultado de decimal para string e pass�-lo para o LCD
         lcd_out(2,7,txt);
         delay_ms(500);
     }
}