
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int zor = 0;
        for(int i=0; i<nums.size();i++){
            zor ^= nums[i];
        }
        return zor;
    }
};





/*class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map <int,int> result;
        int x;
        for(int i =0 ; i<nums.size();i++){
            int value = count(nums.begin(),nums.end(),nums[i]);
            result[nums[i] ]= value;
        }
        for(const auto &val : result){
            if (val.second == 1){
                x =  val.first;
            }
        
        }
        return x;
    }
};*/