class Solution {
public:
    int maxHeight = 0;
    int MOD = 1e9 + 7;
    void heightOfTree(int node, int parent_node, int height,
                      vector<vector<int>>& adj) {
        maxHeight = max(maxHeight, height);

        for (auto child:adj[node]) {
            if (child != parent_node) {
                heightOfTree(child, node, height + 1, adj);
            }
        }
    }

    long long power(long long a, long long b) {
        long long res = 1;

        for (int i = 0; i < b; i++) {
            res = (res * a) % MOD;
        }

        return res;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<vector<int>> adj(n + 2);

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        heightOfTree(1, -1, 0, adj);

        return power(2, maxHeight - 1);
    }
};