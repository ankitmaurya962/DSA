class Solution {
  public:
    int f(vector<int>& arr, int target, int n, vector<vector<int>>&dp){
        if(n == 0){
            if(target == 0 && arr[n] == 0) return 2;
            if(target == 0 || target == arr[n]) return 1;
            return 0;
        }
        
        if(dp[n][target]!=-1) return dp[n][target];
        
        int pick = 0;
        if(arr[n] <= target) pick = f(arr, target-arr[n], n-1, dp);
        int notPick = f(arr, target, n-1, dp);
        
        return dp[n][target] = pick + notPick;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        
        vector<vector<int>>dp(n, vector<int>(target+1, -1));
        return f(arr, target, n-1, dp);
    }
};