class Solution {
    public int maxProfit(int[] prices) {
       int minimum = Integer.MAX_VALUE;
       int maximum = Integer.MIN_VALUE;

       for(int i=0; i<prices.length; i++){
            minimum = Math.min(minimum,prices[i]);
            int profit = prices[i] - minimum;
            maximum = Math.max(profit,maximum);
       }
       return maximum;
    }
    
}