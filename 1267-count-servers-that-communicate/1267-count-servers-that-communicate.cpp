class Solution {
private:
    int bfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &grid){
        vis[i][j]=1;
        int n = grid.size();
        int m= grid[0].size();
        queue<pair<int,int>> que;
        que.push({i,j});
        int count = 1;
        while(!que.empty()){
            int row = que.front().first;
            int col = que.front().second;
            que.pop();
            int arr1[4] = {0,0,1,-1};
            int arr2[4] = {1,-1,0,0};
            for(int i=0; i<4; i++){
                int nrow = row + arr1[i];
                int ncol = col + arr2[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                    count++;
                    vis[nrow][ncol] = 1;
                    que.push({nrow,ncol});
                }
            }
        }
        return count;
    }
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int total = 0;
        int sum =0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0; i<n; i++ ){
            for(int j=0; j<m ; j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    sum = bfs(i,j,vis,grid);
                    if(sum>1) total+=sum;
                }
                 
            }
        }  
        return total;
    }
};