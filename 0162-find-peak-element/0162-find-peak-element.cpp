class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) return 0; // Only one element, it's the peak
        if(nums[0] > nums[1]) return 0; // First element is a peak
        if(nums[n-1] > nums[n-2]) return n-1; // Last element is a peak

        for(int i = 1; i < n-1; i++) {
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
                return i; // Found a peak
            }
        }
        
        return -1; // Should never reach here for valid input
    }
};


/*intuition if the mid or standing element is greater than mid + 1; that means peak elem is 
in right half so eliminate left half , else eliminate the right half

brute  loop through the array  from index 0 if arr[i]> arr[i+1] return i;*/