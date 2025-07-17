class Solution {
private:
    void bfs(int row, int col , vector<vector<int>> &image, int color){
        int curColor = image[row][col];
        image[row][col] = color;
         if(curColor == color) return; 
        queue<pair<int,int>> que;
        int n = image.size();
        int m = image[0].size();
        que.push({row,col});
        while(!que.empty()){
            int curRow = que.front().first;
            int curCol = que.front().second;
            que.pop();
            for(int delrow =-1; delrow<=1; delrow++){
                for(int delcol=-1; delcol<=1; delcol++){
                    if(abs(delrow) == abs(delcol)) continue; // skipping horizontal;
                    //checking boundary;
                    int nrow = curRow + delrow;
                    int ncol = curCol + delcol;
                    if(nrow >=0 && nrow<n && ncol >=0 && ncol<m && image[nrow][ncol] == curColor){
                        image[nrow][ncol] = color;
                        que.push({nrow,ncol});
                    }
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //so i will do a bfs;
        int n = image.size();
        bfs(sr,sc,image,color);
        return image;
    }
};