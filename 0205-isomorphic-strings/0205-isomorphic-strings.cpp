class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char>mp;
          map<char,char>mp2;
        for(int i=0; i<s.size(); i++){
            char c1 = s[i] , c2 = t[i];
            if(mp.count(c1) && mp[c1]!=c2) return false;
            if(mp2.count(c2) && mp2[c2] != c1) return false;
            mp[c1] = c2;
            mp2[c2] = c1;
        }
        return true;
    }
};

/*if(s.size()!= t.size()) return false;
        for(int i= 0; i<s.size(); i++){
            char c1 = s[i];
           if(map.count(c1) == 0)
        }
        string res ="";
        for(int i=0; i<s.size(); i++){
           res+=mp[s[i]]; 
        }
        if(res == t) return true;
        return false;*/