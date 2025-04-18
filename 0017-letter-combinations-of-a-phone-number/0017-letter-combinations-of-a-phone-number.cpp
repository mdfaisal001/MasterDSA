class Solution {
    
private:
        unordered_map<char, string> mp= {
                {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };


    void findCombination(int index , string combination, vector<string> &result, string &digits){
        if(index == digits.size()){
            result.push_back(combination);
        }
        
        string temp = mp[digits[index]];
        for(char ch : temp){
            combination.push_back(ch);
            findCombination(index+1,combination,result,digits);
            combination.pop_back();
        }
}

public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
       string combination ="";
       vector<string> result;
       findCombination(0,combination,result,digits);
       return result;
    }
};