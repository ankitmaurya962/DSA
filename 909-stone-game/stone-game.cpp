class Solution {
public:
int f(int i, int j, vector<int>&nums, vector<vector<int>>&dp){
        if(i > j) return 0;

        if(i == j) return nums[i];

        if(dp[i][j]!=-1) return dp[i][j];
        
        int takefirst = nums[i] + min(f(i+2, j, nums, dp), f(i+1, j-1, nums, dp));
        int takelast = nums[j] + min(f(i+1, j-1, nums, dp), f(i, j-2, nums, dp));

        return dp[i][j] = max(takefirst, takelast); 
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        
        for(auto it: nums) sum += it;

        vector<vector<int>>dp(n, vector<int>(n, -1));

        int p1 = f(0, n-1, nums, dp);
        int p2 = sum - p1;

        
        return p1 >= p2;
    }
    bool stoneGame(vector<int>& piles) {
        return predictTheWinner(piles);
    }
};