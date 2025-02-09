class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long totalPairs = (long long)n * (n - 1) / 2; // Total pairs in the array

        unordered_map<int, long long> freq; // To store frequency of nums[i] - i
        long long goodPairs = 0;

        for (int i = 0; i < n; i++) {
            int key = nums[i] - i;

            // If key already exists in the map, it means there are good pairs with this key
            if (freq.find(key) != freq.end()) {
                goodPairs += freq[key]; // Add all pairs formed by current index
            }

            // Update frequency of the current key
            freq[key]++;
        }

        // Calculate bad pairs as total pairs - good pairs
        return totalPairs - goodPairs;
    }
};
