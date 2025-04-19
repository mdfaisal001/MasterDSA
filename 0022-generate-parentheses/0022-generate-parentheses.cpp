class Solution {
private:
    void findParanthesis(int open,int close, vector<string> &result, string temp, int n){
        if(temp.size() == n *2){
            result.push_back(temp);
            return;
        }
        /* my approach is the reverse process taking the open and close n and each call decreaseit
        if open<n we can pick and add (  else if close < open that means theres a open parantheses so we can use close paranthese
        so we can add ) and decrease the close -1 , base cas if(close ==0 && open == 0){ result.push(temp)} // but what we did is 
        opposite tho this and another base case usually uses for any the combintion generated length is n *2)*/
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

/*class Solution { this is what actually we do ! manually undoing
private:
    void findParanthesis(int open, int close, vector<string> &result, string &temp, int n) {
        if (temp.size() == n * 2) {
            result.push_back(temp);
            return;
        }

        if (open < n) {
            temp.push_back('(');                     // choose
            findParanthesis(open + 1, close, result, temp, n); // explore
            temp.pop_back();                         // undo (backtrack)
        }

        if (close < open) {
            temp.push_back(')');
            findParanthesis(open, close + 1, result, temp, n);
            temp.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        int open = 0, close = 0;
        vector<string> result;
        string temp;
        findParanthesis(open, close, result, temp, n);
        return result;
    }
};

\U0001f6a9 The Two Versions:
✅ 1. Pass-by-value (Your Original Code):

findParanthesis(open + 1, close, result, temp + "(", n);
Here:

You create a new string every time: temp + "("

So each recursive call works with its own independent copy of temp

No need to pop_back() or undo anything

✅ 2. Pass-by-reference + pop_back (Modified Version):

temp.push_back('(');
findParanthesis(open + 1, close, result, temp, n);
temp.pop_back();
Here:

temp is passed by reference, not copied

You manually modify and undo changes to the same string

You must explicitly backtrack (via pop_back())


*/