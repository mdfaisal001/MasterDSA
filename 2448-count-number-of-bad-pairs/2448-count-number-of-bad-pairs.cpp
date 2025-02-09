class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
       long long int n= nums.size();
       long long int size = n *(n-1)/2;
       unordered_map<int,long long> freq;
       long long goodPair = 0;
       for(int i=0; i<n; i++){
            int temp = nums[i]-i;
            if(freq.find(temp)!=freq.end()){
                goodPair+=freq[temp];
            }
            freq[temp]++;
       }
       return size - goodPair;
    }
};
/* int n = nums.size();
        long long int count = 0;
        unordered_map<int,int> map;
        for(int i = 0 ; i<n ; i++){
            for(int j=0; j<n; j++){
                
                if(i<j && nums[i]-i != nums[j]-j){
                    map[i]++;
                }
            }
        } // shows tle  56/65  need to optimize
        for(auto pair : map){
            count+=pair.second;
        }
        return count;
    } 


     int n = nums.size();
        long long int count = 0;
        for(int i = 0 ; i<n ; i++){
            for(int j=0; j<n; j++){
                
                if(i<j && nums[i]-i != nums[j]-j){
                    count++;
                }
            }
        } // shows tle  56/65  need to optimize
        return count;
    } */


    