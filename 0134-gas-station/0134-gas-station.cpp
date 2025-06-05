class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int currentGas = 0 ,start=0;
        for(int i=0; i<gas.size(); i++){
            int gain = gas[i] - cost[i];
            totalGas+=gain;
            currentGas+=gain;
            if(currentGas <0){
                start = i+1;
                currentGas = 0;
            } // calculating the breaking point,we can definitely say it wont be the st point so we are updating the st point to the next index;
        }
        return (totalGas>=0)?start:-1;
    }
};