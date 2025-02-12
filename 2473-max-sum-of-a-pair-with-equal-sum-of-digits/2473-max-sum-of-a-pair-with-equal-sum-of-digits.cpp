class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> digitSumMap; // Maps digit sum to the largest number with that sum
        int maxi = -1; // Initialize to -1 for no valid pair case

        for (int num : nums) {
            int sum = 0, temp = num;

            // Calculate the digit sum of the number
            while (temp > 0) {
                sum += temp % 10;
                temp /= 10;
            }

            // Check if there is already a number with the same digit sum
            if (digitSumMap.find(sum) != digitSumMap.end()) {
                // Update the maximum sum of the pair
                maxi = max(maxi, digitSumMap[sum] + num);

                // Update the largest number for this digit sum
                digitSumMap[sum] = max(digitSumMap[sum], num);
            } else {
                // Store the number as the largest for this digit sum
                digitSumMap[sum] = num;
            }
        }

        return maxi;
    }
};

/*  int maximumSum(vector<int>& nums) {
        priority_queue<pair<int, int>> pq;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int sum = 0; // Sum of digits
            int num = nums[i]; // Temporary variable for digit extraction
            while (num > 0) {
                sum += num % 10; // Add last digit to sum
                num /= 10;       // Remove last digit
            }
            pq.push({sum, nums[i]});
        }

        unordered_map<int, int> map;
        int maxi = 0;

        while (!pq.empty()) {
            int cost = pq.top().first;
            int elem = pq.top().second;
            pq.pop();

            if (map.find(cost) != map.end()) {
                map[cost] += elem;
                maxi = max(maxi, map[cost]);
            } else {
                map[cost] = elem;
            }
        }
        if(maxi == 0) return -1;
        return maxi;
    }*/