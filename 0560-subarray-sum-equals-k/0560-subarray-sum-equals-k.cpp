class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0, sum =0;
        unordered_map<int,int> prefix;
        prefix[0] = 1;
        for(int i=0; i<n ; i++){
            sum+=nums[i];

            if(prefix.find(sum-k) != prefix.end()){
                count+=prefix[sum-k];
            }
            prefix[sum]++;
        }
        return count;
    }
};