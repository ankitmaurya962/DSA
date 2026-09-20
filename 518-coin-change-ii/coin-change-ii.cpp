class Solution {
public:
    int f(vector<int>&coins, int amount, int n, vector<vector<int>>&dp){
        if(amount == 0) return 1;
        if(n == 0){
            if(amount % coins[n] == 0) return 1;
            return 0;
        }

        if(dp[n][amount]!=-1) return dp[n][amount];
        int pick = 0;
        if(amount >= coins[n]) pick = f(coins, amount-coins[n], n, dp);
        int notPick = f(coins, amount, n-1, dp);

        return dp[n][amount] = pick + notPick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount + 1, -1));
        
        return f(coins, amount, n-1 ,dp);
    }
};