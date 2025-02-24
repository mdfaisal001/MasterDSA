class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // Return k-th missing number
        int n = arr.size();
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int missing = arr[mid] -(mid+1);
            if(missing < k){
                low = mid+1;
            }
            else high = mid-1;
        }
        return low + k; // CHAECK NOTE FOR DETAIL;
    }
};


/* unordered_map<int, int> map;
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

        return missingNumbers[k - 1];*/