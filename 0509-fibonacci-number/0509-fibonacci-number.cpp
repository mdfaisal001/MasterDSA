class Solution {
    vector<int> dp; 
public:
    int fib(int n) {
        if(n<=1) return n;
        return fib(n-1) + fib(n-2);
    }
}; // memoization, furhter optimized the space by tabulation;