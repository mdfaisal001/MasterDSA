class Solution {
    private int findSubarr(int[]nums, int goal){
        int l=0,r=0,n=nums.length;
        if(goal < 0) return 0;
        int sum = 0,count=0;
        while(r < n){
            sum+=nums[r];
          

            while(sum > goal){
                sum-=nums[l];
                l++;
            }
          count+=(r-l+1);
          r++;
        }

        return count;
    }
    public int numSubarraysWithSum(int[] nums, int goal) {
        return findSubarr(nums,goal) - findSubarr(nums,goal-1);
        
    }
}