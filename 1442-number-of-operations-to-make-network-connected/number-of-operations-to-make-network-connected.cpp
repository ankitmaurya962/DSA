class Solution {
public:
    void dfs(vector<vector<int>>&adj, int node, vector<int>&vis){
        vis[node] = 1;

        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(adj, it, vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {

        if(connections.size() < n-1) return -1;
        vector<vector<int>>adj(n);
        for(auto it: connections){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        } 
        vector<int>vis(n, 0);

        int components = 0;
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                components++;
                dfs(adj, i, vis);
            }
        }

        return components - 1;
    }
};