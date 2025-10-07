class Solution {
    private int findDays(int[] weights,int weight){
        int sum = 0, days = 1;
        for(int i=0; i<weights.length; i++){
            if(sum + weights[i] > weight){
                days++;
                sum = 0;
            }
            sum+=weights[i];
        }
        return days;
    }
    public int shipWithinDays(int[] weights, int days) {
         int low = Arrays.stream(weights).max().getAsInt();
        int high = Arrays.stream(weights).sum();
        while(low <= high){
            int mid = low + (high - low)/2;
            int requiredDay = findDays(weights,mid);

            if(requiredDay > days){
                low = mid+1;
            }
            else high = mid-1;
        }
        return low;// low is started in the notpossible side;
    }
        
 }
