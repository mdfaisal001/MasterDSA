class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int increment = 1;
        int decrement = 1;
        int ans = 1;
        int n = nums.size();
        if(n==1) return 1;
        for(int i=1;i<n;i++){
           if(nums[i]>nums[i-1]){
             increment++,decrement=1;
           }
            
           else if(nums[i]<nums[i-1]){
             decrement++; increment = 1;
           }
           else{
            decrement =1 , increment =1;
           } 
           ans = max({ans,increment,decrement});
        }
       
        return ans;
    }
};

