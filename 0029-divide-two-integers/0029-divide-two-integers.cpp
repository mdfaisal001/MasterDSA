class Solution {
public:
    int divide(int dividend, int divisor) {
        
        
        
        //sign
        bool isPositive = true;
        if(dividend >=0 && divisor <0) isPositive = false;
        if(dividend <=0 && divisor >0) isPositive = false;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(divisor == 1) return dividend;
        

        long int n = dividend;
        long int d = divisor;
        n = abs((long)dividend);
        d = abs((long)divisor);
        int ans = 0;
        while(n >= d){
            int count = 0;
            while(count < 31 && n >= (d*(1<<count))){
                count++;
            }
            ans += (1<<count-1);
            n -=(d * (1<<count-1));
        }
         if(ans == (1 << 31) && isPositive ) return INT_MAX;
        if(ans == (1 << 31) && !isPositive) return INT_MIN;
        return(isPositive)? ans : -1*ans;
    }
};