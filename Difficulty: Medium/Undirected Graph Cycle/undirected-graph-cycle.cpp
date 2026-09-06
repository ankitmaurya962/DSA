class Solution {
  public:
    bool dfs(int node, vector<vector<int>>&adj, vector<int>&vis, int parent){
        vis[node] = 1;
        
        for(auto it: adj[node]){
            if(vis[it] && it!=parent) return true;
            else if(vis[it] == 0){
                if(dfs(it, adj, vis, node)) return true;
            }
        }
        
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        int n = edges.size();
        vector<vector<int>>adj(V);
        
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(V, 0);
        for(int i = 0; i<V; i++){
            if(vis[i] ==0){
                if(dfs(i, adj, vis, -1)) return true;
            }
            
        }
        
        return false;
    }
};