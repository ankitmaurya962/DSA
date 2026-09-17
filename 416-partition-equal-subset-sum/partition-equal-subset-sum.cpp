class Solution {
public:
    bool f(vector<int>&nums, int i, int target, vector<vector<int>>&dp){
        if(target == 0) return true;

        if(i == 0) return nums[i] == target;

        if(dp[i][target] != -1) return dp[i][target];

        bool pick = false;
        if(nums[i] <= target) pick = f(nums, i-1, target-nums[i], dp);
        bool notPick = f(nums, i-1, target, dp);

        return dp[i][target] = pick || notPick;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        
        int sum = 0;
        for(auto it: nums) sum += it;

        if(sum%2!=0) return false;
        int target = sum/2;

        vector<vector<int>>dp(n, vector<int>(target + 1, -1));
        return f(nums, n-1, target, dp);
    }
};