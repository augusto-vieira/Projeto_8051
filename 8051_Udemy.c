void main() {

     /*  Vamos programar o Port 1 e o port 2
            Ambas as portas são de 8 bits de largura, bidirecionais e têm pull-ups internos, antes, nós conectamos P0 com
            resistores de pull-up externos.
            Mas não há necessidade de nenhum resistor de pull up para os Ports P1 e P0 (já possuem internos)

                 Por padrão, ambas as portas são configuradas como entrada na energização.

            Vamos fazer um programa simples que irá definir a porta 1 como entrada e a porta 2 como saída
            e qualquer entrada que eu aplicar na porta 1 será enviada para a porta 2
     */

   
     P1 = 0xff;                         // 1111-1111  PORT1 (1-Input)
     P2 = 0x00;                         // 0000-0000  PORT2 (0-Output)
     while(1){
        P2 = P1;                        // Port2 igual a o Port1
     }
     

}