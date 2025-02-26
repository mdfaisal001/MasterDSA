class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        string word;
        vector<string>result;
        while(iss >> word){
            result.push_back(word);
        }
        reverse(result.begin(),result.end());
        string updated;
        int n= result.size();
        for(int i=0; i<n ;i++){
            if(i==n-1){
             updated +=result[i] ;
             continue; 
            } 
            updated += result[i] + " ";
        }
        return updated;
    }
};