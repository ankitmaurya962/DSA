class Solution {
public:
    int f(int i, int j, vector<vector<int>>& obstacleGrid,
          vector<vector<int>>& dp) {
        if (i < 0 || j < 0 || obstacleGrid[i][j] == 1)
            return 0;
        if (i == 0 && j == 0)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        int right = f(i, j - 1, obstacleGrid, dp);
        int down = f(i - 1, j, obstacleGrid, dp);

        return dp[i][j] = right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>> dp(n, vector<int>(m));
        dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (i == 0 && j == 0)
                    continue;

                int right = 0;
                int down = 0;

                if (obstacleGrid[i][j] == 0) {
                    if (j > 0)
                        right = dp[i][j - 1];
                    if (i > 0)
                        down = dp[i - 1][j];
                }

                dp[i][j] = right + down;
            }
        }
        return dp[n - 1][m - 1];
    }
};