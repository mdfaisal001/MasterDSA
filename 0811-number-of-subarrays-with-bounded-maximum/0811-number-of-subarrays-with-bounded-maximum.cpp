class Solution {
int findSubarray(vector<int> &nums, int bound){
     int l=0,r=0, n= nums.size(),count=0;
        while(r < n){
             if(nums[r] > bound){
                l = r+1;
             }
             count+=(r-l+1);
             r++;
        }
        return count;
}
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
       return findSubarray(nums,right) - findSubarray(nums,left-1);
    }
};