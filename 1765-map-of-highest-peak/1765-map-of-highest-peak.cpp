class Solution {
private:
    void bfs(int row, int col, int diff, vector<vector<int>> &height,int n, int m){
        height[row][col] =0;
        queue<pair<int,pair<int,int>>> que;
        que.push({diff,{row,col}});
        int arr1[4] = {0,0,1,-1};
        int arr2[4] = {1,-1,0,0};
        while(!que.empty()){
            int hei = que.front().first;
            int Row = que.front().second.first;
            int Col = que.front().second.second;
            que.pop();
             for(int i =0; i<4 ; i++){
                int nrow = Row + arr1[i];
                int ncol = Col + arr2[i];
                if(nrow >=0 && nrow<n && ncol >=0 && ncol<m ){
                    height[nrow][ncol] = hei + 1;
                    que.push({height[nrow][ncol],{nrow,ncol}});
                }
             }
        }
    }
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> height(n,vector<int>(m,0));
        for(int i=0; i<n;i++){
            for(int j=0; j<m; j++){
                if(isWater[i][j]==1){
                    bfs(i,j,0,height,n,m);
                }
            }
        }
        return height;
    }
};