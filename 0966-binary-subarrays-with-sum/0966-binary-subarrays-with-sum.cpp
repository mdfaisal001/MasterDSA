class Solution {
private:
    int findSubarray(vector<int> &nums, int goal){
        if (goal < 0) return 0;
        int l=0, r= 0, n = nums.size(), valid=0, sum=0;
        while(r < n){
            sum+=nums[r];
            while(sum > goal){
                sum-=nums[l];
                l++;
            }
            valid  += (r - l +1);
           r++;
        }
        return valid;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return findSubarray(nums,goal) - findSubarray(nums,goal-1);
    }
};