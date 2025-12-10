class Solution {
private:
    int findSum(int divisor,vector<int> &nums){
        int total =0;
        for(int i=0; i<nums.size(); i++){
            total += ceil((double)nums[i] / divisor);
        }
        return total;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());

        while(low <= high){
            int mid = low + (high - low)/2;
            int currentThreshold = findSum(mid,nums);

            if(currentThreshold > threshold){
                low = mid+1;
            }
            else high = mid-1;
        }
        return low;
    }
};