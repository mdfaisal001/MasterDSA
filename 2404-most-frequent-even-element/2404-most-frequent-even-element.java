class Solution {
    public int mostFrequentEven(int[] nums) {
        
        Arrays.sort(nums);
        int ans = -1;
        int maxi = Integer.MIN_VALUE;

        for(int i=0;i<nums.length;){
            if((nums[i] & 1) == 1){
                i++;
                continue;
            }
            int count = 0;
            int elem = nums[i];
            while(i<nums.length && nums[i] == elem){
                count++;
                i++;
            }

            if(count > maxi){
                maxi =  count;
                ans = elem;
            }
        }

        return ans;
    }
}