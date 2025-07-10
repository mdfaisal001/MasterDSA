class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        hash[0] = -1; // base case: subarray from beginning
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int mod = (k == 0) ? sum : sum % k;

            if (hash.find(mod) != hash.end()) {
                if (i - hash[mod] >= 2) return true;
            } else {
                hash[mod] = i;
            }
        }

        return false;
    }
};
