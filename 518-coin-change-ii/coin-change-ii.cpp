class Solution {
public:
    // int f(vector<int>&coins, int amount, int n, vector<vector<int>>&dp){
    //     if(amount == 0) return 1;
    //     if(n == 0){
    //         if(amount % coins[n] == 0) return 1;
    //         return 0;
    //     }

    //     if(dp[n][amount]!=-1) return dp[n][amount];
    //     int pick = 0;
    //     if(amount >= coins[n]) pick = f(coins, amount-coins[n], n, dp);
    //     int notPick = f(coins, amount, n-1, dp);

    //     return dp[n][amount] = pick + notPick;
    // }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount + 1, 0));
        
        for(int i = 0; i<n; i++){
            dp[i][0] = 1;
        }

        for(int i = 0; i<=amount; i++){
            if(i % coins[0] == 0) dp[0][i] = 1;
            else dp[0][i] = 0;
        }

        for(int i = 1; i<n; i++){
            for(int j = 1; j<=amount; j++){
                long long pick = 0;
                if(j >= coins[i]) pick = (dp[i][j-coins[i]]); 
                long long notPick = dp[i-1][j];

                dp[i][j] = pick + notPick;
            }
        }

        return (int)dp[n-1][amount];
    }
};