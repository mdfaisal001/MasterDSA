class Solution {
    public int firstMissingPositive(int[] nums) {
        HashMap<Integer,Integer> mp = new HashMap<>();
        for(int i=0; i<nums.length; i++){
            mp.put(nums[i],i);
        }

        for(int i=1 ; i<=nums.length ;i++){
            if(!mp.containsKey(i)){
                return i;
            }
        }
        return nums.length + 1;
    }
}