class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>firstOccur;
        int n=nums.size(), prefix = 0;
        firstOccur[0] = -1;
        for(int i=0; i<n;i++){
            prefix+=nums[i];
            if(firstOccur.find(prefix%k) != firstOccur.end()){
                 if(i-firstOccur[prefix%k] >= 2) return true;
            }
            else{
                firstOccur[prefix % k] = i;
            }
      }
       return false;

    }      
    
};
