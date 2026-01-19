class Solution {
    private long findHour(long bananasPerHr,int[] piles){
        long hour = 0;
        for(int i =0; i<piles.length; i++){
            hour += (int)(Math.ceil((double)piles[i] / bananasPerHr));
        }
        return hour;
    }
    public int minEatingSpeed(int[] piles, int h) {
        long low = 1, high = Arrays.stream(piles).max().getAsInt();

        while(low <= high){
            long mid = low + (high - low) /2 ;
            long findHour = findHour(mid,piles);
            if(findHour <= h) {
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        return (int)low;
    }
}