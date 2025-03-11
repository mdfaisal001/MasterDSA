class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            map<char,int> mp;
            for(int j = i ; j<n; j++){
                mp[s[j]]++; // for each possible substr calculating the freq;
                
                auto mini = min_element(mp.begin(),mp.end(),
                [](const auto &a , const auto &b) {return a.second < b.second ;});
                auto maxi = max_element(mp.begin(), mp.end(),[]
                (const auto &a, const auto &b) {return a.second < b.second ;}); // lamda fun to find

                /* we can use it too  for(auto it:mpp){
                    maxi = max(maxi,it.second);
                    mini = min(mini,it.second);
                } */



                int maximum = maxi->second;
                int minimum = mini->second;
                sum +=(maximum - minimum);
            }
        }
       return sum;
    }
};

/*class Solution {
    // optimal 
    class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int sum = 0;

        for(int i = 0; i < n; i++) {
            int freq[26] = {0}; // Frequency array for characters

            for(int j = i; j < n; j++) {
                freq[s[j] - 'a']++; // Update frequency

                // Find min and max frequency (excluding 0s)
                int mini = INT_MAX, maxi = INT_MIN;
                for(int k = 0; k < 26; k++) {
                    if(freq[k] > 0) { // Consider only present characters
                        mini = min(mini, freq[k]);
                        maxi = max(maxi, freq[k]);
                    }
                }

                sum += (maxi - mini);
            }
        }
        return sum;
    }
};

private:
    void frequency(map<char,int> &mp , string &substring){
            for(char c : substring){
                mp[c]++;    
        }
    }
public:
    int beautySum(string s) {
        vector<string>substring;
        int sum = 0;
        for(int i=0; i<s.size(); i++){
            for(int j=0; j< s.size();j++){
                string temp="";
                for(int k=i; k<=j;k++){
                     temp +=s[k];
                }
                substring.push_back(temp);
            }
        }
        map<char,int>mp;
        for(auto substr : substring){
            frequency(mp,substr);
            auto minimum = min_element(mp.begin(), mp.end(), 
    [](const auto &a, const auto &b) { return a.second < b.second; });
            auto maximum = max_element(mp.begin(), mp.end(), 
    [](const auto &a, const auto &b) { return a.second < b.second; });
            int maxi = maximum->second;
            int mini = minimum->second;
            int total = maxi - mini;
            sum+=total;
            mp.clear();
        }
        return sum;
    }
};*/