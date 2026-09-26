class Solution {
public:
    bool f(string &s, string &p, int n1, int n2, vector<vector<int>>&dp){
        if(n1 < 0 && n2 < 0) return true;

        if(n2 >=0 && n1 < 0) {
            bool flag = true;
            for(int i = n2; i>=0; i--){
                if(p[i] != '*'){
                    flag = false;
                }
            }
            return flag;
        } 
        if(n2 < 0)
            return false;


        if(dp[n1][n2]!= -1) return dp[n1][n2];

        if(p[n2] == s[n1] || p[n2] == '?') return dp[n1][n2] = f(s, p, n1-1, n2-1, dp);
        if(p[n2] == '*') return dp[n1][n2] = f(s, p, n1-1, n2, dp) || f(s, p, n1, n2-1, dp);

        return dp[n1][n2] = false;
    }
    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();

        vector<vector<int>>dp(n1, vector<int>(n2, -1));
        return f(s, p, n1-1, n2-1, dp);
    }
};