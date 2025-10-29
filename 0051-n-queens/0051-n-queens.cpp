class Solution {
private:
    bool isSafe(int row , int col , vector<string> &board , int n){
        for(int i = 0; i<n; i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        } // checking the same column upwards;

        //checking the top left diagonal
        for(int i=row-1,j=col-1; i>=0 && j>=0; i--,j--){
            if(board[i][j] == 'Q') return false;
        }

        //checking the right diagonal;
        for(int i=row-1 ,j=col+1; i>=0 && j<n; i--,j++){
            if(board[i][j] == 'Q') return false;
        }

        return true;
    }

    void solveQueen(int index, vector<string> board, int n,vector<vector<string>> &result ){
         if(index == n){
            result.push_back(board);
            return;
         }

         for(int i=0; i<n;i++){
            if(isSafe(index,i,board,n)){
                board[index][i] = 'Q';
                solveQueen(index+1,board,n,result);
                board[index][i] = '.';
            }
         }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> result;
        solveQueen(0,board,n,result);
        return result;
        
    }
};