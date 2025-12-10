class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(),farthest = 0;
        if(n == 1) return true;
        for(int i=0; i<n-1; i++){
            farthest = max(farthest,nums[i]+i);
            if(farthest <=i)return false; //if it doesnt cross the own index;
            if(farthest >= n-1) return true;
        }
        return false;
    }
};