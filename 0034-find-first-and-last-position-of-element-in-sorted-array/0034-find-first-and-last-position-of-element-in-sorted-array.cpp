class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>vec(2,-1);
        int low = 0;
        int high = nums.size()-1;
        int result = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid]== target){
                result = mid;
                high = mid-1;
            }
            else if(nums[mid] <target) { 
                low = mid + 1;
            }
            else {
                high = mid-1;
            }
        }
        if(result != -1 && nums[result]==target) vec[0] = result;
        
        if(result !=-1){
                    int start = 0;
                    int end = nums.size()-1;
                    int last = -1;
                    while(start <= end){
                        int mid = start + (end - start) / 2;
                        if(nums[mid]==target){
                            last = mid;
                            start = mid+1;
                        }
                        else if(nums[mid] > target){
                            end = mid-1;
                        }
                        else{
                            start = mid + 1;
                        }
                    }
                    vec[1] = last;
                    }
                
        return vec;
    }
};

/* for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] == target) {
                vec[1] = i;
                break;  // Stop at the first found target from the right
            }
        } brute for last occurence */


// we can solve it by lowerbound and upperbound-1 bcx upperb end before the actual elem 