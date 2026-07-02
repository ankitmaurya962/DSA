class Solution {
public:
    int bfs(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, INT_MAX));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;

        vis[0][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0}); // {cost, row, col}

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!pq.empty()) {
            int cost = pq.top()[0];
            int x = pq.top()[1];
            int y = pq.top()[2];
            pq.pop();

            // Ignore outdated entries
            if (cost > vis[x][y])
                continue;

            if (x == n - 1 && y == m - 1)
                return cost;

            for (int i = 0; i < 4; i++) {
                int row = x + drow[i];
                int col = y + dcol[i];

                if (row >= 0 && row < n && col >= 0 && col < m) {
                    int newCost = cost + grid[row][col];

                    if (newCost < vis[row][col]) {
                        vis[row][col] = newCost;
                        pq.push({newCost, row, col});
                    }
                }
            }
        }

        return -1;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        return bfs(grid) < health ? true : false;
    }
};