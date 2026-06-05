class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low =0;
        int high = m*n-1;

        while(low <= high){
            int mid = low + (high - low)/2;
            int row = mid/n; //To track the row suppose the mid is 9, the col is 4, 9/4 will be 2 so we know our 9 th value was at the third row thats how we got 2, and the remainder 1 is the actual 9 the values position.
            int col = mid %n;

            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target) low = mid + 1;
            else high = mid -1;
        }
        return false;
    }
};