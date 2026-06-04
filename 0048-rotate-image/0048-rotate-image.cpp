class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int  n = matrix.size();

        //to traverse one part above the 
        for(int i=0;i<n-1;i++){

            for(int j=i+1; j<n; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        

        for(int i=0;i<matrix.size(); i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }  
};


/*class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int  n = matrix.size();
        vector<vector<int>> rotated(n,vector(n,0));
        for(int row =0; row < n; row++){
            for(int col=0; col< matrix[0].size(); col++){
                  rotated[col][n-row-1] = matrix[row][col];
            }
        }

        for(int i=0;i<rotated.size(); i++){
            for(int j=0;j<rotated[0].size(); j++){
                matrix[i][j] = rotated[i][j];
            }
        }
    }  //brute solution   
};*/