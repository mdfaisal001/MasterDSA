class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int ps = 0 , ns = 0;
        for(int i=0;i<nums.size(); i++){
            if(nums[i]==0)  continue;
            if(nums[i]>=0) ps++;
            else ns++;
        }
        int maxi = max(ps,ns);
        return maxi;
    }
};