class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis);
            }
        }
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // Edge case: Not enough cables
        if (connections.size() < n - 1)
            return -1;

        // Build the adjacency list
        vector<vector<int>> adj(n);
        for (auto it : connections) {
            int val1 = it[0];
            int val2 = it[1];
            adj[val1].push_back(val2);
            adj[val2].push_back(val1);
        }

        // Count the number of connected components
        vector<int> vis(n, 0);
        int connectedComponents = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                connectedComponents++;
                dfs(i, adj, vis);
            }
        }

        // Number of operations needed to connect all components
        return connectedComponents - 1;
    }
};
