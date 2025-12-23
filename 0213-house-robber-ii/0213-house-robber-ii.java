class Solution {

    private int findCost(int start, int end, int[] nums, int[] dp){
        
        for(int i=end-1 ; i>=start; i--){
            dp[i] = Math.max((nums[i] +dp[i+2]), dp[i+1]);
        }
        return dp[start];
    }
    public int rob(int[] nums) {
        if(nums.length ==1)return nums[0];
        if(nums.length ==2) return Math.max(nums[0],nums[1]);
        int n = nums.length;
        int[] dp1 = new int[n+2];
        int[] dp2 = new int[n+2];
        Arrays.fill(dp1,0);
        Arrays.fill(dp2,0);
        int firstSet = findCost(0,n-1,nums,dp1);
        int secondSet = findCost(1,n,nums,dp2);
        int result = Math.max(firstSet,secondSet);
        return result;
    }
} 