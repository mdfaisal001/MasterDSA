class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
       vector<int> temp;
       if(s1==s2) return true;
       for(int i=0; i<s1.size(); i++){
          if(s1[i]!=s2[i]) temp.push_back(i);
       }
       if(temp.size()==2){
            int first = temp[0] , last= temp[1];
            return s1[first] == s2[last] && s1[last] == s2[first];
       }
       return false;
    }
};