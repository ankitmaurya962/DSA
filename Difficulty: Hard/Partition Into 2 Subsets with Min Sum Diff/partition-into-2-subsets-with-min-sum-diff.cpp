class Solution {
	public:
	int minDifference(vector<int>& arr) {
		// code here
		int n = arr.size();
		int k = 0;
		for (int i = 0; i<arr.size(); i++) {
			k += arr[i];
		}
		
		vector<vector<int>> dp(n, vector<int>(k + 1));
		
		// sum == k -> always true
		for (int i = 0; i < n; i++) {
			dp[i][k] = true;
		}
		
		// n == 0
		for (int sum = 0; sum <= k; sum++) {
			if (arr[0] + sum == k) {
				dp[0][sum] = true;
			}
		}
		
		for (int i = 1; i<n; i++) {
			for (int sum = k; sum >= 0; sum--) {
				// pick
				bool pick = false;
				if (sum + arr[i] <= k) {
					pick = dp[i - 1][sum + arr[i]];
				}
				
				// notPick
				bool notPick = dp[i - 1][sum];
				
				dp[i][sum] = pick || notPick;
			}
		}
		
		int minDiff = INT_MAX;
		
		int sum = 0;
		for (int i = 0; i <= k; i++) {
			if (dp[n - 1][i]) {
				minDiff = min(minDiff, abs(i - (k - i)));
			}
		}
		
		return minDiff;
	}
};
