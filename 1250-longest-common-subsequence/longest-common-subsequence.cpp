class Solution {
public:
    int f(string &text1, string &text2, int i, int j, vector<vector<int>>&dp){

        if(i == 0 || j == 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        //match
        if(text1[i-1] == text2[j-1]) {
            return dp[i][j] = 1 + f(text1, text2, i - 1, j - 1, dp);
        }

        //notmatch
        return dp[i][j] = max(f(text1, text2, i - 1, j, dp), f(text1, text2, i, j - 1, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();

        vector<vector<int>>dp(n1 + 1, vector<int>(n2 + 1, -1));
        
        return f(text1, text2, n1, n2, dp);
    }
};