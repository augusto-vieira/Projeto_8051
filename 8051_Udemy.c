void main() {

     P0 = 0x0f;                         // 0000-1111 (0-Output & 1-Input)
     while(1){
       
        /* O que esse código vai fazer? ele simplesmente lerá P0 bit 0 e gravará no P0 bit 4
            Da mesma forma, o bit 1 será gravado no bit 5
            bit 2 será escrito para bit 6 e bit 3 de P0 será escrito para bit 7 de P0
            bit 2 será escrito para bit 6 e bit 3 de P0 será escrito para bit 7 de P0
            
             seja qual for a entrada que eu aplico no bit 0,1,2 e 3
             o mesmo está aparecendo no bit 4,5,6 e 7 respectivamente
        */
       
        // acesso individual bit a bit no MikroC
        P0.B4 = P0.B0;
        P0.B5 = P0.B1;
        P0.B6 = P0.B2;
        P0.B7 = P0.B3;
     }
     

}