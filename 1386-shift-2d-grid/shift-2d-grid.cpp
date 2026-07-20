class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();

        vector<vector<int>> temp = grid;
        for (int i = 0; i < k; i++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < grid[i].size() - 1; j++) {
                    temp[i][j + 1] = grid[i][j];
                }
            }

            vector<int> lastCol;
            int m = grid[0].size();
            for (int i = 0; i < n; i++) {
                lastCol.push_back(grid[i][m - 1]);
            }

            // right rotate by 1
            int last = lastCol.back();

            for (int i = lastCol.size() - 1; i > 0; i--) {
                lastCol[i] = lastCol[i - 1];
            }

            lastCol[0] = last;

            for (int i = 0; i < n; i++) {
                temp[i][0] = lastCol[i];
            }

            grid = temp;
        }

        return grid;
    }
};