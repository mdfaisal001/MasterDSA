class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        string input1 = strs[0];
        for(int i=1; i<strs.size(); i++){
           while(strs[i].find(input1) !=0){
             input1 = input1.substr(0,input1.size() -1);
             if(input1.empty()) return "";
           }
        }
       return input1;
    }
};

// !=0 edge case;