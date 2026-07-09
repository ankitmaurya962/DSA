class Solution {
public:
    int find(int i, vector<int>& parent) {
        if (i == parent[i]) {
            return i;
        }

        return parent[i] = find(parent[i], parent);
    }

    void Union(int x, int y, vector<int>& parent, vector<int>& rank) {
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);

        if (x_parent == y_parent)
            return;

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {

        vector<int> parent(n);
        // parent initialisation
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        vector<int> rank(n, 0);

        // Union nodes on condition
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i-1] <= maxDiff) {
                Union(i, i-1, parent, rank);
            }
        }

        vector<bool> ans;
        // traversing queries
        for (auto it : queries) {
            int x_parent = find(it[0], parent);
            int y_parent = find(it[1], parent);

            if (x_parent == y_parent)
                ans.push_back(true);
            else
                ans.push_back(false);
        }

        return ans;
    }
};