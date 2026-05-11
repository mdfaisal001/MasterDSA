class Solution {
private:
    void findCombination(int index, vector<int> candidates, vector<int> &temp, vector<vector<int>> &result, int target){
        if(target < 0 || index == candidates.size()) return ;

        if(target == 0){
            result.push_back(temp);
            return;
        }

        for(int i=index;i<candidates.size(); i++){
            temp.push_back(candidates[i]);
            findCombination(i,candidates,temp,result,target-candidates[i]);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> result;

        findCombination(0,candidates,temp,result,target);
        return result;
    }
};