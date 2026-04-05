class Solution {
public:
    void dfs(int node, int parent, vector<vector<int>>&bridges, vector<int>&disc, vector<int>&low, vector<int>&vis, vector<vector<int>>&adj, int &count){

        disc[node] = low[node] = count;
        vis[node] = 1;

        for(auto it: adj[node]){
            if(it == parent) continue;

            else if(vis[it] == 1){
                low[node] = min(low[node], disc[it]);
            }else{
                count++;
                dfs(it, node, bridges, disc, low, vis, adj, count);
                low[node] = min(low[node], low[it]);

                if(disc[node] < low[it]){
                    bridges.push_back({node, it});
                }
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);

        for(auto it: connections){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>>bridges;
        vector<int>disc(n);
        vector<int>low(n);
        vector<int>vis(n, 0);
        int count = 0;
        dfs(0, -1, bridges, disc, low, vis, adj, count);

        return bridges;
    }
};