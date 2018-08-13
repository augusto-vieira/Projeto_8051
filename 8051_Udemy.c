void main() {

     P0 = 0x0f;                         // 0000-1111 (0-Output & 1-Input)
     while(1){
        P0.B4 = P0.B0;                  // acesso individual bit a bit no MikroC
        P0.B5 = P0.B1;
        P0.B6 = P0.B2;
        P0.B7 = P0.B3;
     }
     

}