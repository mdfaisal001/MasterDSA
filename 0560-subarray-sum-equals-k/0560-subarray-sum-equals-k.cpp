class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0, sum =0;
        unordered_map<int,int> hash;
        for(int i = 0; i<n ; i++){
              sum+=nums[i];
              if(sum==k) count++;
             int rem = sum - k;
             if(hash.find(rem)!=hash.end()){
                 count+=hash[rem];
             }
             hash[sum]++; //inthis problem we need to know how many k present in sum-k;
             
        }
        return count;
    }
};