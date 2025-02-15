class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int peak = 0;
        for(int i = 1 ; i<nums.size() -1 ; i++){
            if(nums[i] > nums[i-1] && nums[i]> nums[i+1]){
                peak = i;
                return peak;
            }
        }
        return (nums[0] >= nums[nums.size()-1]) ? 0 : nums.size()-1;
    }
};