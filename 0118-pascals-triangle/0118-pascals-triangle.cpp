class Solution {
private:
    void pascal(vector<vector<int>> &matrix,vector<vector<int>> &result){
       
        matrix[1][1] = 1;
        vector<int> temp;
        temp.push_back(matrix[1][1]);
        result.push_back(temp);
        int size = 2;

        for(int i=2; i<matrix.size(); i++){
            temp.clear();
            for(int j=1;j<=size; j++){
                matrix[i][j] = matrix[i-1][j-1] + matrix[i-1][j];
                temp.push_back(matrix[i][j]);
            }
           
            result.push_back(temp);
            
            size++;
        }
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> matrix(numRows+1, vector<int>(numRows + 1, 0));
        vector<vector<int>> result;
        pascal(matrix,result);
        return result;
    }
};