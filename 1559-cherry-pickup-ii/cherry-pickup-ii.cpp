class Solution {
public:
    int f(vector<vector<int>> &grid, int r1j, int r2j, int i, int n, vector<vector<vector<int>>>&dp){
        if(r1j < 0 || r1j>=grid[i].size() || r2j < 0 || r2j>=grid[i].size()) return 0;

        if(i == n){
            if(r1j == r2j) return grid[i][r1j];
            else return grid[i][r1j] + grid[i][r2j];
        }

        if(dp[r1j][r2j][i] != -1) return dp[r1j][r2j][i];
        int d[3] = {-1, 0, 1};

        int maxCollection = 0;
        for(int j = 0; j<3; j++){
            for(int k = 0; k<3; k++){
                int moves = 0;
                if(r1j == r2j) moves = grid[i][r1j] + f(grid, r1j + d[j], r2j + d[k], i + 1, n, dp);
                else moves = grid[i][r1j] + grid[i][r2j] + f(grid, r1j + d[j], r2j + d[k], i + 1, n, dp);
                maxCollection = max(maxCollection, moves);
            }
        }

        return dp[r1j][r2j][i] = maxCollection;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>>dp(m, vector<vector<int>>(m, vector<int>(n, -1)));
        return f(grid, 0, m-1, 0, n-1, dp);
    }
};