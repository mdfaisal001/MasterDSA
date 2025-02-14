class Solution {
public:
   
        vector<int> rank,parent;
        void dsu(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i=0; i<n; i++){
                parent[i] = i;
            }
        }
        int findParent(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node] = findParent(parent[node]);
        }
        void unionBySize(int u, int v){
            int ult_u = findParent(u);
            int ult_v = findParent(v);
            if(rank[ult_u]> rank[ult_v]){
                parent[ult_v] = ult_u;
            }
            else if(rank[ult_v] > rank[ult_u]){
                parent[ult_u] = ult_v;
            }
            else{
                parent[ult_u] = ult_v;
                rank[ult_u]++;
            }
        }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        dsu(n);
        unordered_map<string,int> map;
        for(int i = 0; i<n; i++){
            for(int j = 1 ;j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(map.find(mail)==map.end()){
                    map[mail] = i;
                }
                else{
                    unionBySize(i,map[mail]);
                }
            }
        } 
        vector<vector<string>> merge(n);
        for(auto it : map){
            int index = it.second;
            int parent = findParent(index);
            merge[parent].push_back(it.first);
        }
        vector<vector<string>> result;
        for(int i = 0;i<merge.size(); i++){
            vector<string>temp;
            if(merge[i].size()==0) continue;
            sort(merge[i].begin(),merge[i].end());
            string name = accounts[i][0];
            temp.push_back(name);
            for(auto iter : merge[i]){
                temp.push_back(iter);
            }
            result.push_back(temp);
        }
        return result;
    }
};