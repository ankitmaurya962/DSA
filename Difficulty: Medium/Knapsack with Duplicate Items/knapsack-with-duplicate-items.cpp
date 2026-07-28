class Solution {
public:
    int f(int n, int w, vector<int>& wt, vector<int>& val,
          vector<vector<int>>& dp) {

        if (n == 0) {
            return (w / wt[0]) * val[0];
        }

        if (dp[n][w] != -1)
            return dp[n][w];

        int notPick = f(n - 1, w, wt, val, dp);

        int pick = 0;
        if (wt[n] <= w)
            pick = val[n] + f(n, w - wt[n], wt, val, dp);

        return dp[n][w] = max(pick, notPick);
    }

    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
        return f(n - 1, capacity, wt, val, dp);
    }
};