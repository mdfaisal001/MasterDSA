class Solution {
private:
    void findParanthesis(int open,int close, vector<string> &result, string temp, int n){
        if(temp.size() == n *2){
            result.push_back(temp);
        }
        if(open<n) findParanthesis(open+1,close,result,temp + "(",n);
        if(close <open) findParanthesis(open,close+1,result,temp+")",n);
    }
public:
    vector<string> generateParenthesis(int n) {
        int open = 0;
        int close = 0;
        vector<string> result;
        string temp = "";
        findParanthesis(open, close, result,temp,n);
        return result;
    }
};