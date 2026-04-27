class Solution {
public:
    bool isValid(int newR, int newC, int row, int col,
                 unordered_map<int, vector<vector<int>>>& mp,
                 vector<vector<int>>& grid) {
        for (auto it : mp[grid[newR][newC]]) {
            int prevRow = newR + it[0];
            int prevCol = newC + it[1];

            if (prevRow == row && prevCol == col)
                return true;
        }
        return false;
    }
    bool dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int row,
             int col, int n, int m,
             unordered_map<int, vector<vector<int>>>& mp) {
        vis[row][col] = 1;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int newR = drow[i] + row;
            int newC = dcol[i] + col;

            if (newR >= 0 && newR < n && newC >= 0 && newC < m &&
                vis[newR][newC] != 1) {
                bool canGo = false;
                for (auto it : mp[grid[row][col]]) {
                    if (row + it[0] == newR && col + it[1] == newC) {
                        canGo = true;
                        break;
                    }
                }
                if (canGo && isValid(newR, newC, row, col, mp, grid)) {
                    if (newR == n - 1 && newC == m - 1)
                        return true;
                    else {
                        if (dfs(grid, vis, newR, newC, n, m, mp))
                            return true;
                    }
                }
            }
        }

        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (n == 1 && m == 1)
            return true;

        vector<vector<int>> vis(n, vector<int>(m, 0));
        unordered_map<int, vector<vector<int>>> mp{
            {1, {{0, -1}, {0, 1}}},  {2, {{1, 0}, {-1, 0}}},
            {3, {{0, -1}, {1, 0}}},  {4, {{1, 0}, {0, 1}}},
            {5, {{-1, 0}, {0, -1}}}, {6, {{-1, 0}, {0, 1}}},
        };

        return dfs(grid, vis, 0, 0, n, m, mp);
    }
};