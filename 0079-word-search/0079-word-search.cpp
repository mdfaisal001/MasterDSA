class Solution {
private:
    bool dfs(int row, int col , vector<vector<char>> &board , string word,int index){
       if(index == word.size()) return true;
        

        if(row<0 || row>=board.size() || col<0 || col >=board[0].size()  || board[row][col] != word[index]) return false;
        char temp = board[row][col];
        board[row][col] = '#';
        for(int i=-1 ; i<=1; i++){
            for(int j=-1 ; j<=1; j++){
                if(abs(i) == abs(j)) continue;
                 int nrow = row + i;
                 int ncol = col + j;
                    
                    if(dfs(nrow,ncol,board,word,index+1)) return true;
                   
                 }
            }
            board[row][col] = temp;
            return false;
        }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                    if(board[i][j]==word[0]) {
                        if( dfs(i,j,board,word,0)){
                            return true;
                        }
                    }
            }
        }
        return false;
    }
};
/*
 ->return the subbool fun directly on the public bool func
 -parameters -> board, word, starting point.
 i have a thought store all the charcters in the map, with their pos
 for example the starting character  is a but we have 2 position that the a exists,we should
 try all the position , even after completed all the existing indexes and still not able 
 to visit the word mean return false , if can mean return true;

 ->but actually i didnt know hot to write code for this, because its my overall thought
 process not a structural thought process with recursion tree,
 hope it will complete.
         1.main
         2.map
         3.to store all the positions of the chr in map(unordered);
         4.recursive backtracking with dfs
         5.hope it will be done by me within today*/