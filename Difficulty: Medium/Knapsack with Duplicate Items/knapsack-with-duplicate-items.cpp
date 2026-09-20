class Solution {
  public:
  
    int f(vector<int>&val, vector<int>&wt, int capacity, int n, vector<vector<int>>&dp){
        if(n == 0) {
            if(wt[0] <= capacity) return (capacity/wt[n]) * val[0];
            
            return 0;
        }
        
        if(dp[n][capacity] != -1) return dp[n][capacity];
        int pick = 0;
        if(capacity >= wt[n]) pick = val[n] + f(val, wt, capacity-wt[n], n, dp);
        int notPick = f(val, wt, capacity, n-1, dp);
        
        return dp[n][capacity] = max(pick, notPick);
    }
    
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        
        int n = val.size();
        vector<vector<int>>dp(n, vector<int>(capacity + 1, -1));
        return f(val, wt, capacity, n-1, dp);
    }
};