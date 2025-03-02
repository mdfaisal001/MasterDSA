class Solution {
public:
    string removeOuterParentheses(string s) {
        
        string result = "";
        stack<char>st;
        for(char c : s){
            if(c == '('){
                if(!st.empty()) result += c;
                st.push(c);
            }
            else if(c == ')'){
                st.pop();
                if(!st.empty()) result += c; 
            }
        }
        
        return result;
    }
};
/*for(char c : s){
    int count = 0;
            if(c == '('){
                if(count > 0) result+=c;
                count++;
            }
            if(c == ')'){
                count--;
                if(count>0) result+=c;
            }
        } */