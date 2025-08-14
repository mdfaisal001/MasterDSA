class Solution {
private:
    void findSubset(int index, vector<int> &temp, vector<vector<int>> &result,vector<int>nums ){
        result.push_back(temp);
        if(index==nums.size()) return;

        for(int i=index ; i<nums.size(); i++){
            if(i > index && nums[i] == nums[i-1]) continue; //skipping dup
            temp.push_back(nums[i]);
            findSubset(i+1,temp,result,nums);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<vector<int>>result;
        findSubset(0,temp,result,nums);
        return result;
    }
};