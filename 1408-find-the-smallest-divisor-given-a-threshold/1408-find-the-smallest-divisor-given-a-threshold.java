class Solution {
    private int findSum(int[] nums, int div){
        int total = 0;
        for(int i=0; i<nums.length; i++){
            total += (int)Math.ceil((double)nums[i]/div);
        }
        return total;
    }
    public int smallestDivisor(int[] nums, int threshold) {
        int n = nums.length;
        int low = 1, high = Arrays.stream(nums).max().getAsInt();
        while(low <= high){
            int mid = low + (high -low)/2;
            int div = findSum(nums,mid);

            if(div > threshold){
                low = mid+1;
            }
            else high = mid -1;
        }
        return low; // low started with not possible position
    }
}