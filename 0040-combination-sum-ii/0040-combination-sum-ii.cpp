class Solution {
private:
    void getCombination(int index, int target, vector<int> temp, vector<vector<int>> &result, vector<int>& combination) {  
        if (target == 0) {
           result.push_back(temp);
           return;
        }

        
        for(int i = index; i < combination.size();i++){  // to explore multiple option for pick or non pick

      
            if(i > index && combination[i] == combination[i-1]) continue;

                 if(combination[i] > target)  break  ;// if the conditon was broke on the first call theres no meaning to check other calls its definitely have larger elements bcz its sorted
                     temp.push_back(combination[i]);
                     getCombination(i + 1, target - combination[i], temp, result, combination);
                     temp.pop_back();
                
      }
 }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // for consistency
        vector<int> temp;
        vector<vector<int>> result;
        getCombination(0, target, temp, result, candidates);

        return result;
    }
};

/*class Solution {
private:
    void generate(int index, vector<int>& nums, vector<int>& temp, vector<vector<int>>& result, set<vector<int>>& seen) {
        if (index == nums.size()) {
            // Use set to avoid duplicates
            if (seen.find(temp) == seen.end()) {
                result.push_back(temp);
                seen.insert(temp);
            }
            return;
        }

        // Not pick current element
        generate(index + 1, nums, temp, result, seen);

        // Pick current element
        temp.push_back(nums[index]);
        generate(index + 1, nums, temp, result, seen);
        temp.pop_back();  // backtrack
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sorting helps ensure duplicates are adjacent
        vector<vector<int>> result;
        vector<int> temp;
        set<vector<int>> seen; // to avoid duplicate subsets

        generate(0, nums, temp, result, seen);
        return result;
    }
}; // brute 2^n logn n
*/ 