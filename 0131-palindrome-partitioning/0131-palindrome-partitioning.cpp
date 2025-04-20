class Solution {
private:
    bool findPalindrome(string substring , int start , int end){
        while(start < end){
            if(substring[start]!=substring[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void findPartition(int start, string &s, vector<string> temp, vector<vector<string>> &result){
        if(start == s.size()){
            result.push_back(temp);
            return;
        }

        for(int end=start; end<s.size(); end++){
            if(findPalindrome(s,start,end)){
                temp.push_back(s.substr(start, end-start +1));
                findPartition(end+1,s,temp,result);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>>result;
        int start = 0;
        findPartition(start,s,temp,result);
        return result;
    }
};