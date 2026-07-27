class Solution {
  public:
    int f(int n, int W, vector<int>&val, vector<int>&wt, vector<vector<int>>&dp){
        if(n == 0){
            if(wt[n]<=W) return val[n];
            return 0;
        }
        
        if(dp[n][W] != -1) return dp[n][W];
        int notPick = f(n-1, W, val, wt, dp);
        int pick = INT_MIN;
        
        if(wt[n]<=W) pick = val[n] + f(n-1, W-wt[n], val, wt, dp);
        
        return dp[n][W] = max(notPick, pick);
        
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        
        vector<vector<int>>dp(n, vector<int>(W+1, -1));
        
        return f(n-1, W, val, wt, dp);
    }
};