class Solution {
public:
    string frequencySort(string s) {
       map<char,int>mp;
       for(auto c :s){
         mp[c]++;
       } 
       priority_queue<pair<int,char>> pq;
       for(auto pair : mp){
            pq.push({pair.second,pair.first});
       }
       string result ="";
       while(!pq.empty()){
         int count = pq.top().first;
         char word = pq.top().second;

         pq.pop();
         while(count > 0) {
            result+=word;
            count--;
         } 
        
       }
       return result;
    }
};