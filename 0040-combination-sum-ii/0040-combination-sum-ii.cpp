class Solution {
private:
    void getCombination(int index, int target, vector<int> temp, vector<vector<int>> &result, vector<int>& combination) {  
        if (target == 0) {
           result.push_back(temp);
           return;
        }

        
        for(int i = index; i < combination.size();i++){  // to explore multiple option

      
            if(i > index && combination[i] == combination[i-1]) continue;
             if(combination[i] <= target) {
                     temp.push_back(combination[i]);
             getCombination(i + 1, target - combination[i], temp, result, combination);
             temp.pop_back();
             }

            
        
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
