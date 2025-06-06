class Solution {

public:
    static bool comparator(const pair<int, int>& a, const pair<int, int>& b) {
        // Sort by end time in ascending order
        return a.first > b.first;
    }
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> pr;
        for(int i=0; i<speed.size(); i++){
            pr.push_back({efficiency[i],speed[i]});
        }
        sort(pr.begin(),pr.end(),comparator);
        priority_queue<int, vector<int>,greater<int>> pq;
        long long speedSum = 0 , maxPerformance = 0;
        int MOD = 1e9 + 7;
        for(int i=0; i<speed.size(); i++){
            int currSpeed = pr[i].second;
            int currEff = pr[i].first;
            pq.push(currSpeed);
            speedSum+=currSpeed;

            if(pq.size() > k){
                speedSum-=pq.top();
                pq.pop();
            }
            maxPerformance = max(maxPerformance , (long long)speedSum * currEff);
        }
        return maxPerformance % MOD;
    }
};