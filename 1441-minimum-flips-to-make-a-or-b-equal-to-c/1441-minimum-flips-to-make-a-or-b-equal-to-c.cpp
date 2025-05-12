class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        for(int i=0; i<32; i++){
            int A_bit = 1 & (a >> i);
            int B_bit = 1 & (b >> i);
            int C_bit = 1 & (c >> i);
            
            if((A_bit | B_bit) != C_bit){
                if(C_bit == 1){
                    flips++;
                }
                else{
                    flips += A_bit + B_bit;
                }
            }
            
        }
        return flips;
    }
};