class Solution {
private:
        void findSubsets(vector<int> nums,int index, vector<int> temp, vector<vector<int>> &result){
            result.push_back(temp);
            if(index == nums.size()) return;
            for(int i = index; i < nums.size(); i++){
                if(i > index && nums[i] == nums[i-1]) continue;
                temp.push_back(nums[i]);
                findSubsets(nums,i+1,temp,result);
                temp.pop_back();
            }
        }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      vector<int> temp;
      vector<vector<int>> result;
      sort(nums.begin(),nums.end());
      findSubsets(nums,0,temp,result);
      return result;
    }
};