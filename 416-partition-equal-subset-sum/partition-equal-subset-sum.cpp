class Solution {
public:
    // bool f(vector<int>&nums, int i, int target, vector<vector<int>>&dp){
    //     if(target == 0) return true;

    //     if(i == 0) return nums[i] == target;

    //     if(dp[i][target] != -1) return dp[i][target];

    //     bool pick = false;
    //     if(nums[i] <= target) pick = f(nums, i-1, target-nums[i], dp);
    //     bool notPick = f(nums, i-1, target, dp);

    //     return dp[i][target] = pick || notPick;
    // }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        
        int sum = 0;
        for(auto it: nums) sum += it;

        if(sum%2!=0) return false;
        int target = sum/2;

        vector<vector<int>>dp(n, vector<int>(target + 1));
        
        for(int i = 0; i<n; i++){
            dp[i][0] = 1;
        }

        for(int i = 1; i<n; i++){
            for(int k = 1; k <= target; k++){
                bool pick = false;
                if(nums[i] <= k) pick = dp[i-1][k-nums[i]];
                bool notPick = dp[i-1][k];

                dp[i][k] = pick || notPick;
            }
        }
        return dp[n-1][target];
    }
};