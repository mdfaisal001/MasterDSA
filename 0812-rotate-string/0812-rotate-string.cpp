class Solution {
public:
    bool rotateString(string s, string goal) {
       if(s.size() == goal.size() && (s+s).find(goal) != string :: npos) return true;
       return false;
 }
};
/* for(int i=0; i<n; i++){
            char first = s[0];
            for(int j=0; j<n-1;j++){
                s[j] = s[j+1];
            }
            s[n-1] = first;
        if(s == goal) return true;
    }
    return false;

     int n = s.size();
        string search = "";
        int i;
       for(i=0; i<n;i++){
        if(s[i]!=goal[0]){
            search+=s[i];
        }
        else break;
       }
       string word = goal.substr(i,n-i);
       if(word.find(search)!= string::npos) return true;
       return false;
    
    */