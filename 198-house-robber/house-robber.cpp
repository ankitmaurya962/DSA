class Solution {
public:
    int rob(vector<int>& nums) {
        int amount = 0;
        int n = nums.size();

        vector<int>dp(n, -1);

        dp[0] = nums[0];

        for(int i = 1; i<n; i++){
           int pick = nums[i];
           if(i > 1) pick = dp[i-2] + nums[i];

           int notPick = dp[i-1];

           dp[i] = max(pick, notPick);
        }

        return dp[n-1];
    }
};