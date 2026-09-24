class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));

        for (int i = 0; i <= n2; i++) {
            dp[0][i] = 0;
        }

        for (int j = 0; j <= n1; j++) {
            dp[j][0] = 0; 
        }

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    continue;
                }
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n1][n2];
    }


    int minInsertions(string s) {
        int n = s.size();
        string s1 = s;
        reverse(s.begin(), s.end());

        return n - longestCommonSubsequence(s, s1);

    }
};