class Solution {
private:
    void permutation(int index, vector<int> &nums, vector<vector<int>> &result ,vector<int>map,vector<int> temp){
       if(index == nums.size()){
            result.push_back(temp);
            return;
       }
       for(int i=0; i<nums.size(); i++){
            if(!map[i]){
                map[i] = 1;
                temp.push_back(nums[i]);
                permutation(index+1,nums,result,map,temp);
                map[i] = 0;
                temp.pop_back();
            }
       }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
       vector<int>map(nums.size(),0);
       vector<vector<int>> result;
       vector<int> temp;
       permutation(0,nums,result,map,temp);
       return result;
    }
};




/*class Solution {
private:
    void findPermutation(int index, vector<int> nums, vector<vector<int>> &result){
        if(index == nums.size() -1) { // by adding -1 we can decrease the one level of recursion , its further efficient
            result.push_back(nums);
            return;
        } // base case
        for(int i = index ; i< nums.size() ; i++){
            swap(nums[index],nums[i]);
            findPermutation(index+1 , nums,result);    // we are giving index +1 not i + 1 so the call goes level by level
            swap(nums[i],nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    findPermutation(0,nums,result);
    return result;   
    }
};*/