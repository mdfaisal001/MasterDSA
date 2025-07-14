class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>hashmap;
        vector<int>result;
        priority_queue<pair<int,int>> pq;
        for(int i=0; i<nums.size(); i++){
                hashmap[nums[i]]++;
        }
        for(auto pair : hashmap){
            pq.push({pair.second,pair.first});
        }

        while(k-- >0 && !pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;// final result of most freq elements
    }
};