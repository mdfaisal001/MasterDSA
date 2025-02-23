class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_map<int, int> map;
        int n = arr.size();

        // Store elements of the array in the map
        for (int i = 0; i < n; i++) {
            map[arr[i]]++;
        }

        vector<int> missingNumbers;
        int i = 1, count = 0;

        // Find missing numbers until we get k of them
        while (count < k) {
            if (map.find(i) == map.end()) { // If i is missing
                missingNumbers.push_back(i);
                count++;
            }
            i++; // Move to next number
        }

        return missingNumbers[k - 1]; // Return k-th missing number
    }
};
