class Solution {
    
    private void swap(int[] nums, int start, int end){
        int temp = nums[start];

        nums[start] = nums[end];
        nums[end] = temp;
    }
    public void sortColors(int[] nums) {
        int n = nums.length;
        int low=0,mid=0,high = nums.length-1;

        //dutch flag algorithm
        while(mid <= high){

            if(nums[mid] ==0){
                swap(nums,mid,low);
                mid++;
                low++; //to maintain 0 to l-1 as 0;
            }
            else if(nums[mid] ==1){
               
                mid++; //to maintain 1 between low to mid-1;
            }
            else{
                swap(nums,high,mid);
                high--; //to maintain the mid to high as unsorted
            }
        }
    }
}