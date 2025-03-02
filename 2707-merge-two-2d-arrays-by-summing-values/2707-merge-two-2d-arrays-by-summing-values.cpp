class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int> map;
        for(auto val : nums1){
            int key = val[0];
            int value = val[1];
            map[key] = value;
        }
        for(auto id : nums2){
            int key2 = id[0];
            int value2 = id[1];
            map[key2]+=value2;
        }
        vector<vector<int>> result;
        for(auto &[it1,it2]:map){
            result.push_back({it1,it2});
        }
        return result;
    }
};