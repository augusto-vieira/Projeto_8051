void main() {

     /*  Vamos programar o Port 1 e o port 2
            Ambas as portas s�o de 8 bits de largura, bidirecionais e t�m pull-ups internos, antes, n�s conectamos P0 com
            resistores de pull-up externos.
            Mas n�o h� necessidade de nenhum resistor de pull up para os Ports P1 e P0 (j� possuem internos)

                 Por padr�o, ambas as portas s�o configuradas como entrada na energiza��o.

            Vamos fazer um programa simples que ir� definir a porta 1 como entrada e a porta 2 como sa�da
            e qualquer entrada que eu aplicar na porta 1 ser� enviada para a porta 2
     */

   
     P1 = 0xff;                         // 1111-1111  PORT1 (1-Input)
     P2 = 0x00;                         // 0000-0000  PORT2 (0-Output)
     while(1){
        P2 = P1;                        // Port2 igual a o Port1
     }
     

}