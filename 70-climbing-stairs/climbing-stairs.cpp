class Solution {
public:
    int func(int n, vector<int>&dp) {
        if (n < 0)
            return 0;
        if(n==0) return 1;

        if(dp[n]!=-1) return dp[n];

        int l = func (n-1, dp);
        int r = func(n-2, dp);

        return dp[n] = l+r;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1, -1);
        return func(n, dp);
    }
};