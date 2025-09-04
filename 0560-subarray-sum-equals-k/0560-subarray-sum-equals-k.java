class Solution {
    public int subarraySum(int[] nums, int k) {
        int n = nums.length;
        int count = 0, sum =0;
        HashMap<Integer,Integer> freq = new HashMap<>(); // prefix;
        freq.put(0,1);
        for(int i=0; i<n ; i++){
            sum+=nums[i];

            if(freq.containsKey(sum-k)){
                count+=freq.get(sum-k);
            }
            freq.put(sum,freq.getOrDefault(sum,0)+1);
        }
        return count;
    }
}