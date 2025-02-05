class Solution {
private:
    vector<int> createRows(int row){
        vector<int> ans;
        int res=1;
        ans.push_back(1);
        for(int col = 1 ; col<row ; col++){
            res = res * (row-col);
            res= res/(col);
            ans.push_back(res);
        }
        return  ans;
    }
public:
    vector<vector<int>> generate(int numRows) {
        int n= numRows;
        vector<vector<int>>result;
        for(int i=1;i<=n ;i++){
            result.push_back(createRows(i));
        }
        return result;
    }
};