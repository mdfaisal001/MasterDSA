class Solution {
private:
    int mst(vector<vector<pair<int,int>>> adj , int n){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<int> vis(n,0);
        int sum =0;
        while(!pq.empty()){
            int weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(vis[node]) continue;
            vis[node] = 1;
            sum+=weight;
            for(auto pair : adj[node]){
               int adjWeight = pair.first;
               int adjNode = pair.second;
               if(!vis[adjNode]){
                    pq.push({adjWeight,adjNode});
               }
            }

        }
        return sum;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // to find the weights by using mahttan distance
        int n = points.size();
        vector<vector<pair<int,int>>>adj(n,vector<pair<int,int>>());
        for(int i=0;i<n;i++){
            for(int j=0; j<n;j++){
                int val = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                adj[i].push_back({val,j});
            }
        }
        return mst(adj,n);
    }
};