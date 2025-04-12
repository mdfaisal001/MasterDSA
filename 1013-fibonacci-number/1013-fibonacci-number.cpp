class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n==1) return 1;
        return fib(n-1) + fib(n-2);
    }
};

/*   int fib_0 = 0;
        int fib_1 = 1;
        if (n<=1) return n;
        int currentFib;
        for(int i=2;i<=n; i++){
            currentFib = fib_0 + fib_1;
            fib_0 = fib_1;
            fib_1 = currentFib;
        }
        return currentFib;*/