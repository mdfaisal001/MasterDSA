class Solution {
private:
    void findCombination(int index,vector<vector<int>> &result,vector<int>temp, int k, int target,vector<int> nums){
        if(target == 0 && temp.size() == k){
            result.push_back(temp);
            return;
        }
        for(int i=index; i<nums.size(); i++){
             if (nums[i] > target) {  // If the number exceeds the target, no need to continue
                break;
                 }
                temp.push_back(nums[i]);
                findCombination(i+1, result, temp, k, target-nums[i],nums);
                temp.pop_back();
            
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
      vector<int> nums = {1,2,3,4,5,6,7,8,9};
      vector<vector<int>> result;
      vector<int> temp;
      findCombination(0,result,temp,k,n,nums);
      return result;
    }
};