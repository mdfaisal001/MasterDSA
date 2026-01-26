class Solution {
private:
void findSubsets(int index,vector<int>&nums,vector<int> &temp,vector<vector<int>> &result){
    if(index == nums.size()){
        result.push_back(temp);
        return;
    }

    temp.push_back(nums[index]);
    findSubsets(index+1,nums,temp,result);
    temp.pop_back();
    findSubsets(index+1,nums,temp,result);
}

public:
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> result;
      vector<int> temp;
      findSubsets(0,nums,temp,result);
      return result;
    }
};