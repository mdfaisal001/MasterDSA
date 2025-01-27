class Solution {
private:
    vector<int> topo(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& adj) {
        vector<int> indegree(numCourses, 0);
        vector<int> order;
        
        // Build the graph (adjacency list) and compute the indegree for each course
        for (const auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }
        
        // Topological Sort (Kahn's Algorithm)
        queue<int> que;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                que.push(i);
            }
        }
        
        while (!que.empty()) {
            int course = que.front();
            que.pop();
            order.push_back(course);
            
            for (int neighbor : adj[course]) {
                if (--indegree[neighbor] == 0) {
                    que.push(neighbor);
                }
            }
        }
        
        return order;
    }

public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> result;
        vector<vector<int>> adj(numCourses);
        
        // Step 1: Perform Topological Sort to get the order
        vector<int> order = topo(numCourses, prerequisites, adj);
        
        // Step 2: Create a map for the topological index of each course
        vector<int> courseIndex(numCourses);
        for (int i = 0; i < numCourses; ++i) {
            courseIndex[order[i]] = i;
        }

        // Step 3: Process each query
        for (const auto& query : queries) {
            int u = query[0], v = query[1];
            // If u appears before v in the topological order, u is a prerequisite of v
            result.push_back(courseIndex[u] < courseIndex[v]);
        }

        return result;
    }
};
