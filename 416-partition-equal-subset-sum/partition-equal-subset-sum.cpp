class Solution {
public:
    bool f(int n, int target, vector<int>&nums, vector<vector<int>>&dp){
        if(target == 0){
            return true;
        }
        if(n == 0){
            return nums[n] == target;
        }
        if(dp[n][target] != -1) return dp[n][target];
        bool notpick = f(n-1, target, nums, dp);
        bool pick = false;
        if(nums[n] <= target){
            pick = f(n-1, target - nums[n], nums, dp);
        }

        return dp[n][target] = notpick || pick;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            sum += nums[i];
        }
        if(sum%2!=0) return false;
        int target = sum/2;
        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));

        return f(n-1, target, nums, dp);
    }
};