class Solution {
  public:
    int f(int W, vector<int> &val, vector<int>&wt, int n, vector<vector<int>>&dp){
        if(n == 0){
            if(W-wt[n] >= 0) return val[n];
            return 0;
        }
        
        if(dp[n][W] != -1) return dp[n][W];
        
        int pick = 0;
        if(W-wt[n] >= 0) pick = val[n] + f(W-wt[n], val, wt, n-1, dp);
        int notPick = f(W, val, wt, n-1, dp);
        
        return dp[n][W] = max(pick,  notPick);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        
        int n = wt.size();
        
        vector<vector<int>>dp(n, vector<int>(W+1, -1));
        
        return f(W, val, wt, n-1, dp);
        
    }
};