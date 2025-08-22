class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int point = -1;
        int n = nums.size();
        for(int i=n-2 ; i>=0 ; i--){
            if(nums[i] < nums[i+1]){
                point = i;
                break;
            }
        } // find the satisfying point;

        //if already in lexigrophically descending oreder reverse the perm;
        if(point == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
       
        for(int i= n-1; i>point; i--){
             if(nums[i] > nums[point]){
                swap(nums[i] , nums[point]);
                break;
             }
        }

        reverse(nums.begin() + point +1 , nums.end());
    }
};