class Solution {
private:
    void setMatrix(int row , int col, vector<vector<int>>& matrix){
         // Set entire column to 0
        for (int i = 0; i < matrix.size(); i++) {
            matrix[i][col] = 0;
        }

        // Set entire row to 0
        for (int j = 0; j < matrix[0].size(); j++) {
            matrix[row][j] = 0;
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<pair<int,int>> zeroes;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j] == 0) {
                    zeroes.push_back({i,j});
                }
            }
        }

        for(auto pr : zeroes){
            setMatrix(pr.first,pr.second,matrix);
        }
    }
};