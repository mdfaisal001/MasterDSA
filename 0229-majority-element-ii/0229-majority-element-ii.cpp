class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int elem1 = 0, elem2 = 1; // must be different initial values
        int count1 = 0, count2 = 0;
        int n = nums.size();

        // Step 1: Find potential candidates
        for (int num : nums) {
            if (num == elem1) count1++;
            else if (num == elem2) count2++;
            else if (count1 == 0) {
                elem1 = num;
                count1 = 1;
            }
            else if (count2 == 0) {
                elem2 = num;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }

        // Step 2: Validate actual counts
        count1 = count2 = 0;
        for (int num : nums) {
            if (num == elem1) count1++;
            else if (num == elem2) count2++;
        }

        // Step 3: Final check for > n/3
        vector<int> result;
        if (count1 > n / 3) result.push_back(elem1);
        if (count2 > n / 3) result.push_back(elem2);
        return result;
    }
};
