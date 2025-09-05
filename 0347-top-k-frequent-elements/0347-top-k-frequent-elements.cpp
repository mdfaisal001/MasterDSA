class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>hashmap;
        vector<int>result;
        int n = nums.size();
        for(int i=0; i<n; i++){
            hashmap[nums[i]]++;
        } // calculating the frequency;
         
         // creating buckets
         vector<vector<int>> bucket(n+1);
        for(auto pr : hashmap){
            bucket[pr.second].push_back(pr.first);
        }

        // getting the frequency from descending because it contains the most freq element;
        
        for(int i = n; i>=0; i--){

            for(auto num : bucket[i]){
                result.push_back(num);
                if(result.size() == k) break;
            }
            if(result.size() == k) break;
        }

       // final result of most freq elements
       return result;
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