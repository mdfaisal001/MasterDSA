class Solution {
public:
  bool isPowerOfTwo(int n) {
    
   if( n >0 && (n & n-1) == 0) return true;
   return false;
  }
};


/*  bool isPowerOfTwo(int n) {
    if (n == 1) return true;         // Base case: 2^0 = 1
    if (n == 0 || n % 2 != 0) return false; // Reject zero or odd numbers
    return isPowerOfTwo(n / 2);      // Recur by dividing n by 2
}*/