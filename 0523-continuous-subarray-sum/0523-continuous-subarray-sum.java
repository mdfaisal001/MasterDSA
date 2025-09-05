class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        int n = nums.length, prefix = 0;
        HashMap<Integer,Integer> firstOcc = new HashMap<>();
        firstOcc.put(0,-1);
        for(int i=0; i<n; i++){
            prefix += nums[i];

            if(firstOcc.containsKey(prefix % k)){
                if(i-firstOcc.get(prefix%k) >= 2) return true;
            }
            else{
                firstOcc.put(prefix%k , i);
            }
        }
        return false;
    }
}