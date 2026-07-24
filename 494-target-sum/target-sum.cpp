class Solution {
public:
int f(int n, vector<int>&arr, int target, vector<vector<int>>&dp){
    if(n == 0){
        if(target == 0 && arr[0] == 0) return 2;
        if(target == 0 || arr[0] == target) return 1;
        return 0;
    }
    if(dp[n][target]!=-1) return dp[n][target];
    int notPick = f(n-1, arr, target, dp);
    int pick = 0;
    if(arr[n] <= target) pick = f(n-1, arr, target-arr[n], dp);

    return dp[n][target] = (notPick + pick)%1000000007;
}

int countPartitions(int n, int d, vector<int> &arr) {
    int sum = 0;
    for(int i = 0; i<arr.size(); i++){
        sum += arr[i];
    }
    if ((sum - d) < 0 || (sum - d) % 2 != 0)
    return 0;
    int target = (sum - d)/2;

    vector<vector<int>>dp(n+1, vector<int>(target+1, -1));

    return f(n-1, arr, target, dp);
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return countPartitions(n, target, nums);
    }
};