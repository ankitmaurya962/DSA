class Solution {
public:
    int f(string &s, string &t, int n1, int n2, vector<vector<int>>&dp){
        if(n2 == 0) return 1;
        if(n1 == 0) return 0;

        if(dp[n1][n2] != -1) return dp[n1][n2];

        if(s[n1-1] == t[n2-1]) return dp[n1][n2] = f(s, t, n1-1, n2-1, dp) + f(s, t, n1-1, n2, dp);

        return dp[n1][n2] = f(s, t, n1-1, n2, dp);
    }
    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();

        vector<vector<int>>dp(n1+1, vector<int>(n2+1, -1));
        return f(s, t, n1, n2, dp);
    }
};