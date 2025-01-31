class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n,INT_MAX));
        for(auto val : edges){
            dist[val[0]][val[1]] = val[2];
            dist[val[1]][val[0]] = val[2];
        }
        for(int i=0; i<n;i++) dist[i][i] = 0;

        for(int via=0;via<n; via++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dist[i][via]==INT_MAX || dist[via][j]==INT_MAX)continue;
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
         }
        int maxCity = n;
        int smallCity  = -1;
        for(int i=0;i<n; i++){
            int count =0;
            for(int j=0; j<n; j++){
                if(dist[i][j]<= distanceThreshold) count++;
            }
            if(count <= maxCity) {
                maxCity = count;
                smallCity = i; // if they ask 
            }
        }
        return smallCity;

     }
};