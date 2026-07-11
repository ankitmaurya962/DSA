class Solution {
public:
    void dfs(int i, vector<vector<int>>&adj, vector<int>&vis, int &nodeCount, int &edgeCount){
        vis[i] = 1;
        nodeCount++;

        for(auto it: adj[i]){
            edgeCount++;
            if(!vis[it]){
                dfs(it, adj, vis, nodeCount, edgeCount);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);

        for(int i = 0; i<edges.size(); i++){
            int x = edges[i][0];
            int y = edges[i][1];

            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        vector<int>vis(n, 0);
        int count = 0;
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                int nodeCount = 0;
                int edgeCount = 0;
                dfs(i, adj, vis, nodeCount, edgeCount);
                int edges = edgeCount/2;
                if(edges == nodeCount*(nodeCount-1)/2){
                    count++;
                }
            }
        }

        return count;
    }
};