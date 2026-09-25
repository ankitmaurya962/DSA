class Solution {
public:
    int f(string word1, string word2, int n1, int n2, vector<vector<int>>&dp){
        if(n1 == 0) return n2;

        if(n2 == 0) return n1;

        if(dp[n1][n2] != -1) return dp[n1][n2];

        if(word1[n1-1] == word2[n2-1]) return dp[n1][n2] = f(word1, word2, n1-1, n2-1, dp);

        int del = 1 + f(word1, word2, n1-1, n2, dp);
        int replace = 1 + f(word1, word2, n1, n2-1, dp);
        int insert = 1 + f(word1, word2, n1-1, n2-1, dp);

        return dp[n1][n2] = min({del, replace, insert});
    }
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();

        vector<vector<int>>dp(n1 + 1, vector<int>(n2 + 1, -1));

        return f(word1, word2, n1, n2, dp);
    }
};