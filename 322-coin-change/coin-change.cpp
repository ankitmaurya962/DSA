class Solution {
public:
    // int f(vector<int>& coins, int amount, int n, vector<vector<int>>&dp){
    //     if(n == 0){
    //         if(amount % coins[n] == 0){
    //             return amount/coins[n];
    //         }
    //         return 1e9;
    //     }
    //     if(dp[n][amount] != -1) return dp[n][amount];
    //     int pick = 1e9;
    //     if(amount >= coins[n]) pick = 1 + f(coins, amount-coins[n], n, dp);
    //     int notPick = f(coins, amount, n-1, dp);

    //     return dp[n][amount] = min(pick, notPick);
    // }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount + 1, -1));
        for(int i = 0; i<=amount; i++){
            if(i % coins[0] == 0){
                dp[0][i] = i/coins[0];
            }else{
                dp[0][i] = 1e9;
            }
        }

        for(int i = 1; i<n; i++){
            for(int j = 0; j<=amount; j++){
                int pick = 1e9;
                if(j >= coins[i]) pick = 1 + dp[i][j - coins[i]];
                int notPick = dp[i-1][j];

                dp[i][j] = min(pick, notPick);
            }
        }
        return dp[n-1][amount] == 1e9 ? -1 : dp[n-1][amount];
    }
};