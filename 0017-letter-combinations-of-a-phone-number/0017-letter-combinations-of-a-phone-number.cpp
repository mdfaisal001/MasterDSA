class Solution {
         unordered_map<char, string> mp= {
                {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };
    private:
        void findCombination(int index, string &temp, vector<string> &result, string &digits){
            if(index == digits.size()){
                result.push_back(temp);
                return;
            }

            string currentString = mp[digits[index]];
            for(int i=0; i<currentString.size() ; i++){
                temp.push_back(currentString[i]);
                findCombination(index+1,temp,result,digits);
                temp.pop_back();
            }
        }

    
private:

public:
    vector<string> letterCombinations(string digits) {
        string temp = "";
        if(digits.empty()) return {};
        vector<string> result;
        findCombination(0,temp,result,digits);
        return result;
    }
};