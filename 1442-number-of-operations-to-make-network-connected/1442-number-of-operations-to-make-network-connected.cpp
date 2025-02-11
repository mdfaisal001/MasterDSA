class Solution {
private:
    void dfs(int node, vector<vector<int>> &adj, vector<int>& vis) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis);
            }
        }
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);
        // edge case
        if (connections.size() < n - 1) return -1;
        for (auto it : connections) {
            int val1 = it[0];
            int val2 = it[1];
            adj[val1].push_back(val2);
            adj[val2].push_back(val1);
        }
        
        int minCount = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]){
                minCount++;
                dfs(i, adj, vis);
            }
        }
        return minCount-1;
    }
};