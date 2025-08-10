class Solution {
private:
    int findSum(vector<int> &nums , int divisor){
        int total = 0;
        for(int i=0; i<nums.size(); i++){
            total+= ceil((double)nums[i] / divisor);
        }
        return total;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low =1, high = *max_element(nums.begin(), nums.end());
        while(low <= high){
            int mid = low + (high - low)/2;
            int sum = findSum(nums,mid);
            if(sum > threshold){
                low = mid+1;
            }
            else high = mid -1;
        }
        return low;
    }
};