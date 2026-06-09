class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        for(int i = 0; i<nums.size(); i++){
            mini = min(nums[i], mini);
            maxi = max(nums[i], maxi);
        }
        long long ans = maxi - mini;
        return ans*k;
    }
};