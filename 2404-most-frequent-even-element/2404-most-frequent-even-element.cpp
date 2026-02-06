class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int>mp;

        for(int i=0; i<nums.size(); i++){
            if( nums[i] %2 == 0){
               mp[nums[i]]++;
            }
        }
        if(mp.size()== 0) return -1;
        int maxi = INT_MIN;
        int even = 0;

        for(auto pr : mp){
            if(pr.second > maxi){
                maxi = pr.second;
                even = pr.first;
            }
            else if(pr.second == maxi){
                even = min(even,pr.first);
            }
        }

        return even;
       
    }
};