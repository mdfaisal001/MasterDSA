class Solution {
private:
    string expandOut(string &s , int left , int right){
        while(left>=0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return s.substr(left+1, right-left-1);
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string longest ="";
        for(int i=0;i<n;i++){
                // odd check
            string odd = expandOut(s,i,i);
            if(odd.size()> longest.size()) longest = odd;
            // even check
            string even = expandOut(s,i,i+1);
            if(even.size() > longest.size()) longest = even;
        }
        return longest;
    }
};
/*class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        map<int,string>mp;
        for(int i=0; i<n; i++){
            string substr ="";
            for(int j=i; j<n; j++){
                substr+=s[j];
                string reversedStr = substr;
                reverse(reversedStr.begin(), reversedStr.end());
                if(substr == reversedStr){
                     int size = substr.size();
                     mp[size] = substr;
                }
            }
        }
        return (mp.empty())?"":mp.rbegin()->second;
    }
}; 
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string longest = "";
        for(int i=0; i<n; i++){
            string substr ="";
            for(int j=i; j<n; j++){
                substr+=s[j];
                string reversedStr = substr;
                reverse(reversedStr.begin(), reversedStr.end());
                if(substr == reversedStr  && substr.length() > longest.length()){
                     longest = substr;
                }
            }
        }
        return longest;
    }
};
 */ // ineffiecient o(n)^3;