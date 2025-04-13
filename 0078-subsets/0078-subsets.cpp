class Solution {
private:
    void findSubset(vector<int> nums,int index, vector<vector<int>> &result,vector<int>temp, int n){
        if(index >= n){
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        findSubset(nums,index + 1, result,temp,n);
        temp.pop_back();
        findSubset(nums,index+1,result,temp,n);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        vector<int> temp;
        findSubset(nums,0,result,temp,n);
        return result;
    }
};