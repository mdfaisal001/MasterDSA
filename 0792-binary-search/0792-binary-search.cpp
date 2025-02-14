class Solution {
private:
    int binarySearch(int low, int high , int target , vector<int>&nums){
        int mid = low + (high-low)/2;
        if(low>high) return -1;
        if(nums[mid]==target) return mid;
        else if(target>nums[mid]) return binarySearch(mid+1,high,target,nums);
        else return binarySearch(low,mid-1,target,nums);
    }
    
public:
    int search(vector<int>& nums, int target) {
       int low = 0 ;
       int high = nums.size()-1;
       return binarySearch(low,high,target,nums);

    }
};