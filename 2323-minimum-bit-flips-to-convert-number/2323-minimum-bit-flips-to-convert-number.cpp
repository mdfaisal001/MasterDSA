class Solution {
private:
    int findSetBit(int diff){
        int count =0;
        while(diff > 0){
            if(diff %2 == 1) count++;
            diff = diff/2;
        }
        return count;
    }
public:
    int minBitFlips(int start, int goal) {
        int diff = start ^ goal;
        return findSetBit(diff);
    }
};