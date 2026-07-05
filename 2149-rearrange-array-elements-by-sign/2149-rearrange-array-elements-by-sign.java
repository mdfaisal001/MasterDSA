class Solution {
    public int[] rearrangeArray(int[] nums) {
         int pos =0, neg = 1;
       int n = nums.length;
       int[] result = new int[n];

       for(int i=0;i<n; i++){
            if(nums[i] >=0){
                result[pos] = nums[i];
                pos+=2;
            }
            else{
               result[neg] = nums[i];
                neg+=2;
            }
       }

       return result;
    }
}