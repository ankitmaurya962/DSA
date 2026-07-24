class Solution {
public:
    int f(int amount, vector<int>&coins, int n, vector<vector<int>>&dp){
        if(amount == 0) return 1;
        if(n == 0){
            if(amount % coins[n] == 0){
                return 1;
            } 
            else return 0;
        }
        if(dp[n][amount] != -1) return dp[n][amount];
        int notPick = f(amount, coins, n-1, dp);
        int pick = 0;
        if(coins[n] <= amount) pick = f(amount - coins[n], coins, n, dp);

        return dp[n][amount] = notPick + pick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount + 1, -1));
        return f(amount, coins, n-1, dp);
    }
};