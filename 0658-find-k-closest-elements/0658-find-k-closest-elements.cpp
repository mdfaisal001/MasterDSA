class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
       priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> result;

        for(int i=0;i<arr.size(); i++){
            int closeness = abs(arr[i]-x);
            pq.push({closeness,arr[i]});
        }

        for(int i=0; i<k; i++){
            result.push_back(pq.top().second);
            pq.pop();
        }
      sort(result.begin(), result.end());
      return result;
    }
};