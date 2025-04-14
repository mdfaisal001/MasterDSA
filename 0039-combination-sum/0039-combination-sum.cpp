class Solution {
private:
    void findCombination(vector<int> candidates , int index,int target,vector<int> temp, vector<vector<int>> &result){
        if(index == candidates.size()){
            if( target == 0){
                result.push_back(temp); 
            }
            return;
        }
        
        if(target-candidates[index] >= 0){ 
            temp.push_back(candidates[index]);
            findCombination(candidates,index,target-candidates[index],temp,result);
            temp.pop_back();
        }
        findCombination(candidates,index +1 , target, temp, result);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<int>temp;
       vector<vector<int>> result;
       findCombination(candidates,0,target,temp,result);
       return result;
    }
};