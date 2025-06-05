class Solution {
public:

    int findMinArrowShots(vector<vector<int>>& points) {
        vector<pair<int,int>> pr;
        for(int i=0; i<points.size(); i++){
            pr.push_back({points[i][1],points[i][0]});
        }
        sort(pr.begin(),pr.end());
        int arrows = 1;
        int bStart = pr[0].second;
        int bEnd = pr[0].first;
        for(int i=1 ; i<pr.size(); i++){
            if(pr[i].second > bEnd){
                arrows++;
                bEnd = pr[i].first;
            }
        }
        return arrows;
    }
};