class Solution {
private:
    int findMax(vector<int> nums){
        int ans = INT_MIN;
        int n = nums.size();
        for(int i=0; i<n; i++){
            ans = max(ans,nums[i]);
        }
        return ans;
    }
    long long ceilDivision(vector<int> nums , int divisor){
        int n = nums.size();
        long long total = 0;
        for(int i=0; i<n; i++){
            total += ceil((double)nums[i] / (double) divisor);
        }
        return total;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = findMax(nums);
        while(low <= high){
            int mid = low + (high - low) / 2;
            long long sum = ceilDivision(nums,mid);
            if(sum <= threshold){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};