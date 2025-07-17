class Solution {
private:
   void bfs(int row, int col ,vector<vector<char>> &grid){
        queue<pair<int,int>>que;
        que.push({row,col});
        grid[row][col] = '0';
        int n = grid.size();
        int m = grid[0].size();
        while(!que.empty()){
            int curRow = que.front().first;
            int curCol = que.front().second;
            que.pop();
            for(int i=-1; i<=1; i++){
                for(int j =-1 ; j<=1 ; j++){
                    int nrow = curRow + i;
                    int ncol = curCol + j;
                    if (abs(i) + abs(j) != 1) continue; //skipping diagonals;
                    if(nrow >=0 && nrow<n && ncol >=0 && ncol<m && grid[nrow][ncol] =='1'){
                        que.push({nrow,ncol});
                        grid[nrow][ncol] = '0';
                    }
                }
            }
        }
   }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int row = 0; row<n; row++){
            for(int col = 0;col<m ; col++){
                if(grid[row][col] == '1') {
                    count++;
                    bfs(row,col,grid);
                }
            }
        }
        return count;
    }
};