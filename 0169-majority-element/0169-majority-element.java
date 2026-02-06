class Solution {
    public int majorityElement(int[] nums) {
        int count = 0;
        int elem = 0;

        for(int i=0;i<nums.length; i++){
            if(count==0){
                elem = nums[i];
                count = 1;
            }
            else if (nums[i] == elem){
                count++;
            }
            else count--;
        }

        int freq = 0;
        for(int j=0; j<nums.length; j++){
            if(nums[j] == elem)  freq++;
        }

        if(freq > nums.length/2) return elem;

        return -1;
    }
}