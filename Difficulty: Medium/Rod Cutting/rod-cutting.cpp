class Solution {
	public:
	int f(int n, int w, vector<int>&price, vector<vector<int>>&dp) {
		if(n == 0){
		    return w * price[0];
		}
		
		if(dp[n][w] != -1) return dp[n][w];
		
		int notPick = f(n-1, w, price, dp);
		int pick = INT_MIN;
		
		if(n+1 <= w) pick = price[n] + f(n, w-(n+1), price, dp);
		
		return dp[n][w] = max(pick, notPick);
	}
	int cutRod(vector<int> &price) {
		// code here
		int n = price.size();
		vector<vector<int>>dp(n, vector<int>(n+1, -1));
		
		return f(n - 1, n, price, dp);
	}
};
