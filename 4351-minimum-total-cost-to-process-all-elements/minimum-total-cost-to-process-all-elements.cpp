class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long mod = 1e9+7;
        long long leftRes = k;
        long long cost = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] <= leftRes){
                leftRes -= nums[i];
            }else{
                long long required = nums[i] - leftRes;
                long long ops = (required + k - 1) / k;
                cost += ops;
                leftRes += k*ops;
                leftRes -= nums[i];
            }
        }

        return (long long)((__int128)cost * (cost + 1) / 2 % mod);
    }
};