class Solution {
private:
    int findLongestSubarray_WithTotalToFind(vector<int> &nums ,int totalToFind,int n){
        int l=0,r= 0;
        int sum = 0, maxLen = -1;
        while(r < n){
            sum+=nums[r];
            while(sum > totalToFind  ){
                sum-=nums[l];
                l++;
            }
            if(sum == totalToFind){
                maxLen = max(maxLen , r-l+1);
            }
            r++;
        }
        return maxLen;
    }
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(),0);
        int n = nums.size();
        int totalToFind = sum -x;
        if(totalToFind < 0) return -1;
         int longestSubarray = findLongestSubarray_WithTotalToFind(nums,totalToFind,n);
         return (longestSubarray == -1)?-1:n - longestSubarray;
        
    }
};