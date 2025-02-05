class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        int maxi = 0;
        if(n < 2) return nums[n-1];
        for(int i=0; i<n ; i++){
        if(nums[i] == 1) {
            sum++;
            maxi = max(maxi,sum);
        } else{
                sum = 0;
            }
        }
        return maxi;
    }

};