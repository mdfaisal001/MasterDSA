class Solution {
public:
    string reverseWords(string s) {
       stringstream ss(s);
       string word;
       vector<string>words;
       while(ss >> word){
          words.push_back(word);
       }
       reverse(words.begin(), words.end());
       string finalString = "";
       for(int i=0; i<words.size(); i++){
            finalString+=words[i];
            if(i!=words.size()-1){
                finalString+=" ";
            }
       }
       return finalString;
    }
};