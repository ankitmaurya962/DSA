class Solution {
public:
    int func(vector<int>&nums, int target, int i, int n, vector<int>&dp){
        if(i == n-1){
            return 0;
        }

        if(dp[i]!=-2) return dp[i];

        int maxi = INT_MIN;
        for(int j = i+1; j<n; j++){
            if(abs(nums[i]-nums[j]) <= target){
                int temp = func(nums, target , j, n, dp);
                if(temp!= INT_MIN){
                    maxi = max(temp + 1, maxi);
                }   
            }
        }
        return dp[i] = maxi;
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>dp(n, -2);

        int ans = func(nums, target, 0, n, dp);
        

        if(ans == INT_MIN) return -1;
        return ans;
    }
};