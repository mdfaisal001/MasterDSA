class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
      int n = nums.size();
      int low = 1;
      int high = n-2;
      if(n==1) return nums[0];
      if(nums[0]!=nums[1]) return nums[0];
      if(nums[n-1]!= nums[n-2]) return nums[n-1] ; // edge cases
      while(low <= high){
        int mid = low + (high - low) / 2;
        if(nums[mid]!=nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];
        if( (mid%2 == 0 && nums[mid]==nums[mid+1]) || (mid%2 == 1 && nums[mid] == nums[mid-1]) ){
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
      }
      return 0;
    }
};

/*  unordered_map<int,int> map;
        for(int i =0 ; i<nums.size(); i++){
            map[nums[i]]++;
        }
        for(auto pair : map){
            if (pair.second < 2) return pair.first;
        }
        return 0;*/