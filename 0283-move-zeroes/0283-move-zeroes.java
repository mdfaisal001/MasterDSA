class Solution {
    private void swap(int[] nums, int start, int end){
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
    }
    public void moveZeroes(int[] nums) {
        int k=0;
        for(int i=0; i<nums.length; i++){
            if(nums[i] != 0){
                swap(nums,i,k);
                k++;
            }
        }
    }
}