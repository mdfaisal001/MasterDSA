class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0, left = 0, bottom = n-1, right = m -1;
        vector<int> result;
        while(top <= bottom && left <= right){

            for(int i=left ; i<= right; i++){
                result.push_back(matrix[top][i]);
              }
            top++;

            for(int i=top ; i<= bottom ;i++){
                result.push_back(matrix[i][right]);
            }
            right--;

            //edge case for one line array;
            if(top <= bottom){
                
                for(int i=right; i>=left; i--){
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            //edge case for no top

            if(left <= right){
                for(int i=bottom ;i>=top; i--){
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }
       return result;
    }
};