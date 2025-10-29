class Solution {
    private boolean dfs(int index,int row,int col,char[][] board, String word){
        if(index == word.length()){
            return true;
        }

        if(row < 0 || row >= board.length || col < 0 || col >= board[0].length || word.charAt(index) != board[row][col]) return false; // boundary cond and string matching


        char temp = board[row][col];
        board[row][col] = '#';

        for(int i=-1; i<=1; i++){

            for(int j=-1; j<=1; j++){
                if(Math.abs(i) == Math.abs(j)) continue; //skipping diagonals

                int newRow = row + i;
                int newCol = col + j;
                
                if(dfs(index+1,newRow,newCol,board,word)) return true;
            }
        }
        board[row][col]= temp;
        return false; 
    }
    public boolean exist(char[][] board, String word) {
        int row = board.length;
        int col = board[0].length;
        
        for(int i=0; i<row; i++){
            
            for(int j=0; j<col ;j++){

               if(word.charAt(0) == board[i][j]){
                    if(dfs(0,i,j,board,word) == true) return true;
               } 
            }
        }
        return false;
    }
}