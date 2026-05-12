class Solution {
         unordered_map<char, string> mp= {
                {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };
    private:
     void findLetterCombination(int index, string &temp, vector<string> &result,string digits){
        if(index == digits.size()){
            result.push_back(temp);
            return;
        }

        string currString = mp[digits[index]];

        for(char c : currString){
            temp.push_back(c);
            findLetterCombination(index+1,temp,result,digits);
            temp.pop_back();
        }
     }


public:
    vector<string> letterCombinations(string digits) {
        string temp="";
        if(digits.size() == 0) return {};
        vector<string> result;

        findLetterCombination(0,temp,result,digits);
        return result;
    }
};