class Solution {
private:
    void dfs(int node,vector<int> &vis,vector<vector<int>> &adj){
        vis[node] = 1;
        for(int val : adj[node]){
            if(!vis[val]){
                dfs(val,vis,adj);
            }
        }   
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<int> vis(n);
        vector<vector<int>> adj(n);
        int province = 0;
        for(int row = 0; row<n; row++){
            for(int col = 0; col<m; col++ ){
                if(isConnected[row][col]==1){
                    adj[row].push_back(col);
                    adj[col].push_back(row);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                province++;
                dfs(i,vis,adj);
            }
        }
        return province;
    }
};