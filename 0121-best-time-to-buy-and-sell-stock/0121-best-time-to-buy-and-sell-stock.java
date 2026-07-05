class Solution {
    public int maxProfit(int[] prices) {
       int mini = Integer.MAX_VALUE, profit = Integer.MIN_VALUE;

        for(int i=0;i<prices.length; i++){
            mini = Math.min(mini,prices[i]);
            profit = Math.max(profit,prices[i]-mini);
        }
        return profit;
    }
    
}