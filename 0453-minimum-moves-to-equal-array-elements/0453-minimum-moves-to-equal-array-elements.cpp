class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int count = 0;int minMove = INT_MAX;
        for(int i=0; i<nums.size() ;i++){
            count+=nums[i];
            minMove = min(minMove,nums[i]);
        }
        return count-minMove*n;
    }
};