class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int sum = 0 , count = 0,i=0;
        int j = people.size()-1;
        while(i<=j){
            if(people[i]+people[j] <=limit ){
                i++;
            }
            j--;
            count++;
        }
        return count;
    }
};