class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        // taking adj list for a reversed graph
        for(int i = 0 ; i<n ; i++){
            for(int val: graph[i]){
                adj[val].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> que;
        vector<int> safeState;
        // finding node which have indegree 0 which is probably the terminalnode
        for(int j =0; j<n ; j++){
            if(indegree[j]==0) que.push(j);
        }

        while(!que.empty()){
            int node = que.front();
            que.pop();
            safeState.push_back(node);
            for(auto neighbour : adj[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    que.push(neighbour);
                }
            }
        }
      sort(safeState.begin(),safeState.end());
      return safeState;
    }
};