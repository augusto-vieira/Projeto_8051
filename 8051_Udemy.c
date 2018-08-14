void main() {

     /*
      vamos configurar P0 e P1 como entrada,enquanto P2 e P3 ser�o configurados como sa�da,
      e vamos somar os valores do P0 com P1 e o resultado dever� ser exibido em 7 segmentos.

       Para fazer isso, primeiro precisamos converter nossos resultados do formato decimal para o formato BCD.
       
      Agora podemos conectar esses 7 segmentos com a porta 2 e a porta 3, pois essas portas ser�o configuradas como sa�das
      vamos adicionar P0 e P1 e armazenar o resultado na vari�vel ----"sum" ----
      a vari�vel 'sum' cont�m o resultado em formato decimal, mas 7 segmentos precisam de dados no formato BCD
      
      Ent�o, primeiro temos que converter o resultado do decimal em BCD, precisamos de outra vari�vel para armazenar dados no formato BCD
      Dec2Bcd16() � fun��o de biblioteca mikroC integrada que converte decimal em n�meros BCD de 16 bits
        A vari�vel "sumInBcdFormat" vai receber o valor convertido para BCD 16bits
        
        Dec2Bcd16() = 16bits ---> (0000000000000000) 1111-1111.0000-0000
         P2 = 11111111 (8bits) gravo uma parte em P2
         P3 = 00000000   "      e o resto em P3

     */

     unsigned int sum, sumInBcdFormat;            // declarando 2 vari�veis

     P0 = 0xff;                                   // 1111-1111  PORT1 (1-Input)
     P1 = 0x00;                                   // 0000-0000  PORT2 (0-Output)
     P2 = 0x00;                                   // Port3 como sa�da
     P3 = 0x00;                                   // Port4  "   sa�da
     
     while(1){
         sum = P0 + P1;                           // Soma o Port0 com Port1;
         sumInBcdFormat = Dec2Bcd16(sum);         // Dec2Bcd16(sum) ==> converte o valor da resposta em BCD de 16 bits
         P2 = sumInBcdFormat;                     // gravamos apenas 8 bits o resto vai para P3
         P3 = sumInBcdFormat >> 8;                // deslocamos � direita 'sumInBcdFormat'  8bits
         
         
     }
     

}