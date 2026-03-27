class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0;
        int high = height.size()-1;


        int Area = 0;
        while(low < high){
            int mini = min(height[low],height[high]);
            int currArea = mini * (high - low );
            Area = max(currArea,Area);

            if(height[low] < height[high]){
                low ++;
            }
            else high--;

        }
        return  Area;
    }
};