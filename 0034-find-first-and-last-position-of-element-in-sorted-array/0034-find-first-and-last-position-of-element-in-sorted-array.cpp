class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>vec(2,-1);
        int low = 0;
        int high = nums.size()-1;
        int result = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid]>= target){
                result = mid;
                high = mid-1;
            }
            else{
                low = mid +1;
            }
        }
        if(result != -1 && nums[result]==target) vec[0] = result;
       
       for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] == target) {
                vec[1] = i;
                break;  // Stop at the first found target from the right
            }
        }
        return vec;
    }
};