class Solution {
    //optimal
    public int longestOnes(int[] nums, int k) {
       int l=0,r=0,n = nums.length,zeroes =0;
       int maxi = Integer.MIN_VALUE;

       while(r < n){
           if(nums[r] == 0) zeroes++;
           
           while(zeroes > k){
              if(nums[l] == 0) zeroes--;
              l++;
           }

           maxi = Math.max(maxi,r-l+1);
           r++;

       }
       return maxi;
    }
}

/* brute 
int maxLen = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int zeroes = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] == 0) zeroes++;

                if (zeroes > k) break;

                maxLen = max(maxLen, j - i + 1);
            }
        }

        return maxLen;
        
    // Better 
    int n= nums.size() , l= 0 ,r =  0 , maxLen = 0, zeroes = 0;
        
        while(r < n){
            if(nums[r] == 0) zeroes++;
            while(zeroes > k){
                if(nums[l] == 0) zeroes--;
                l++;
            }
            if(zeroes <=k){
                maxLen = max(maxLen,r-l+1);
                r++;
            }
        }
        return maxLen;
        
        
         */