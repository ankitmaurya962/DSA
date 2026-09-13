class Solution {
public:
    bool static comp(vector<int> arr1, vector<int> arr2) {
        return arr1[2] < arr2[2];
    }
    vector<int> parent;
    vector<int> rank;

    int find(int i) {
        if (i == parent[i])
            return i;

        return parent[i] = find(parent[i]);
    }

    void Union(int n1, int n2) {
        int parent_n1 = find(n1);
        int parent_n2 = find(n2);

        if (parent_n1 == parent_n2)
            return;

        if (rank[parent_n1] > rank[parent_n2]) {
            parent[parent_n2] = parent_n1;
        } else if (rank[parent_n1] < rank[parent_n2]) {
            parent[parent_n1] = parent_n2;
        } else {
            parent[parent_n1] = parent_n2;
            rank[parent_n2]++;
        }
    }

    int kruskal(vector<vector<int>> adj, int skip, int force) {
        for (int i = 0; i < parent.size(); i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        int sum = 0;
        int count = 0;
        if (force != -1) {
            for (int i = 0; i < adj.size(); i++) {
                if (adj[i][3] == force) {
                    int u = adj[i][0];
                    int v = adj[i][1];
                    int w = adj[i][2];

                    if (find(u) != find(v)) {
                        Union(u, v);
                        sum += w;
                        count++;
                    }
                }
            }
        }

        for (int i = 0; i < adj.size(); i++) {
            if (adj[i][3] == skip)
                continue;

            if(adj[i][3] == force) continue;
            
            int u = adj[i][0];
            int v = adj[i][1];
            int w = adj[i][2];

            if (find(u) != find(v)) {
                Union(u, v);
                sum += w;
                count++;
            }
        }
        if(count < parent.size()-1) return INT_MAX;
        
        return sum;
    }

    vector<vector<int>>
    findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {

        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        rank.resize(n, 0);

        vector<vector<int>> adj;

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj.push_back({u, v, w, i});
        }

        vector<vector<int>> ans(2);

        sort(adj.begin(), adj.end(), comp);

        int mstSum = kruskal(adj, -1, -1);

        for (int i = 0; i < edges.size(); i++) {
            if (kruskal(adj, i, -1) > mstSum)
                ans[0].push_back(i);
            else {
                if (kruskal(adj, -1, i) == mstSum)
                    ans[1].push_back(i);
            }
        }

        return ans;
    }
};