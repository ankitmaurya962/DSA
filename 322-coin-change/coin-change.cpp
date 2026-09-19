class Solution {
public:
    int f(vector<int>& coins, int amount, int n, vector<vector<int>>&dp){
        if(n == 0){
            if(amount % coins[n] == 0){
                return amount/coins[n];
            }
            return 1e9;
        }
        if(dp[n][amount] != -1) return dp[n][amount];
        int pick = 1e9;
        if(amount >= coins[n]) pick = 1 + f(coins, amount-coins[n], n, dp);
        int notPick = f(coins, amount, n-1, dp);

        return dp[n][amount] = min(pick, notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount + 1, -1));
        return f(coins, amount, n-1, dp) == 1e9 ? -1 : f(coins, amount, n-1, dp);
    }
};