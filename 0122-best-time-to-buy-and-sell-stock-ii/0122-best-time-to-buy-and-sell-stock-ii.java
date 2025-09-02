class Solution {
    
    public int maxProfit(int[] prices) {
        int mini = prices[0], total = 0;

        for(int i=0; i<prices.length; i++){
            mini = Math.min(mini,prices[i]);
            if(prices[i] - mini > 0){
                int profit =  prices[i] - mini;
                total+=profit;
                mini = prices[i];
            }
        }
        return total;
    }
}