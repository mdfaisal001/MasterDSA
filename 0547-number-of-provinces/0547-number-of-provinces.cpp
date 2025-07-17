class Solution {
private:
   void bfs(int node,vector<int>&vis , vector<vector<int>> &adj){
        vis[node]=1;
        queue<int>que;
        que.push(node);
        while(!que.empty()){
            int insertedNode = que.front();
            que.pop();
            for(int it :adj[insertedNode]){
                if(!vis[it]){
                    vis[it] = 1;
                    que.push(it);
                }
            }
        }
   }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); //row;
        int m = isConnected[0].size(); // col;
       // vis arr, province,bfs,adjlist
       vector<int>vis(n,0); //0 based
       int province = 0;
       vector<vector<int>> adj(n);//size is must
       for(int row=0; row<m; row++){
           for(int col=0; col<m ;col++){
                if(isConnected[row][col] == 1){
                    adj[row].push_back(col);
                    adj[col].push_back(row);
                }
           }
       }
       for(int i=0; i<n; i++){
            if(!vis[i]){
                province++; //sep comp++;
                bfs(i,vis,adj);
            }
       }
       return province;
    }
};