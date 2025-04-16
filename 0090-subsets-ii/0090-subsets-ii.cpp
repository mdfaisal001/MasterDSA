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