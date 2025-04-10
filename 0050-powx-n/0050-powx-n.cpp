class Solution {
private:
    double pow(double x , long long n){
        if(n==0) return 1;
        if(n%2==0) return  pow(x*x,n/2);
        else return  x* pow(x,n-1);
    }
public:
    double myPow(double x, int n) {
        long long N = n;
        if(N < 0) {
            x = 1 / x;
            N = -N;
        }
        return pow(x,N);
    }

   
};
/*long long exp = n;
      if(exp<0){
        if(exp==INT_MIN){
            if (x==0)return 0;
            x = 1/x;
            exp = -(exp+1);
            return x*myPow(x,exp);
        }
        else{
            x=1/x;
            exp = -(exp);
        }
      }
      double base = x;
      double result = 1.0;
      while(exp > 0){
        if(exp%2 == 1){
            result*=base;
        }
        base*=base;
        exp= exp/2;
      }
     
       return result;*/