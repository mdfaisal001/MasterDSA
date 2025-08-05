class Solution {
private:
    bool isPalindrome(int low , string &s , int high){
        while(low < high){
             if(s[low++] != s[high--]) return false;
        }
        return true;
    }
  void findPartition(int index,string s , vector<vector<string>> &result,vector<string> container){
        if(index == s.size()){
            result.push_back(container);
            return;
        }

        for(int i=index;i<s.size(); i++){
            if(isPalindrome(index,s,i)){
                container.push_back(s.substr(index,i-index+1));
                findPartition(i+1,s,result,container);
                container.pop_back();
            }
        }
  }
public:
    vector<vector<string>> partition(string s) {
       vector<vector<string>> result;
       vector<string> container;
       findPartition(0,s,result,container);
       return result;
    }
};