class Solution {
private:
    void solveNQueen(int row, int col , vector<string> &board , vector<vector<string>> &result,int n){
        if(row == n) {
            result.push_back(board); // base casw when we reach the n the row thats more than the col we push the total board
        }

        for(int i=0;i<n;i++){
            if(isSafe(row,i,board,n)){
                board[row][i] = 'Q';
                solveNQueen(row+1,i,board,result,n);
                board[row][i] = '.';
            }
        }
    }
    bool isSafe(int row, int col , vector<string> &board,int n){
        // to check column;
        for(int i=0; i<n; i++){
            if(board[i][col] == 'Q') return false;
        }
        // for topleft diagonal
        for(int i = row-1, j = col-1 ; i>=0 && j>=0 ; i--,j--){
            if(board[i][j] == 'Q') return false;
        }

        // for right top diagonal
        for(int i = row-1,j=col+1; i>=0 && j<n;  i--,j++){
            if(board[i][j]=='Q') return false;
        }
        return true;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string>board(n,string(n,'.'));
        solveNQueen(0,0,board,result,n);
        return result;
    }
};