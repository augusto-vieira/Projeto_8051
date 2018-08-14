void main() {

     /*
      vamos configurar P0 e P1 como entrada,enquanto P2 e P3 serão configurados como saída,
      e vamos somar os valores do P0 com P1 e o resultado deverá ser exibido em 7 segmentos.

       Para fazer isso, primeiro precisamos converter nossos resultados do formato decimal para o formato BCD.
       
      Agora podemos conectar esses 7 segmentos com a porta 2 e a porta 3, pois essas portas serão configuradas como saídas
      vamos adicionar P0 e P1 e armazenar o resultado na variável ----"sum" ----
      a variável 'sum' contém o resultado em formato decimal, mas 7 segmentos precisam de dados no formato BCD
      
      Então, primeiro temos que converter o resultado do decimal em BCD, precisamos de outra variável para armazenar dados no formato BCD
      Dec2Bcd16() é função de biblioteca mikroC integrada que converte decimal em números BCD de 16 bits
        A variável "sumInBcdFormat" vai receber o valor convertido para BCD 16bits
        
        Dec2Bcd16() = 16bits ---> (0000000000000000) 1111-1111.0000-0000
         P2 = 11111111 (8bits) gravo uma parte em P2
         P3 = 00000000   "      e o resto em P3

     */

     unsigned int sum, sumInBcdFormat;            // declarando 2 variáveis

     P0 = 0xff;                                   // 1111-1111  PORT1 (1-Input)
     P1 = 0x00;                                   // 0000-0000  PORT2 (0-Output)
     P2 = 0x00;                                   // Port3 como saída
     P3 = 0x00;                                   // Port4  "   saída
     
     while(1){
         sum = P0 + P1;                           // Soma o Port0 com Port1;
         sumInBcdFormat = Dec2Bcd16(sum);         // Dec2Bcd16(sum) ==> converte o valor da resposta em BCD de 16 bits
         P2 = sumInBcdFormat;                     // gravamos apenas 8 bits o resto vai para P3
         P3 = sumInBcdFormat >> 8;                // deslocamos à direita 'sumInBcdFormat'  8bits
         
         
     }
     

}