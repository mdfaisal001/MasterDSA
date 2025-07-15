class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>hashmap;
        vector<int>result;
        priority_queue<pair<int,int>> pq;
        for(int i=0; i<nums.size(); i++){
                hashmap[nums[i]]++;
        }
        vector<vector<int>>bucket(nums.size() +1);
        for(auto pair : hashmap){
            bucket[pair.second].push_back(pair.first);
        } // added in the bucket 

        for(int j = nums.size(); j>=0 ; j--){
            //buckets have multiple elements;
            for(auto num : bucket[j]){
                result.push_back(num);
                if(result.size() == k) break;
            }
            if(result.size() == k) break;
        }
        // more or  less to O(n)
        return result;
       // final result of most freq elements
    }
};

/*class Solution {
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
};*/