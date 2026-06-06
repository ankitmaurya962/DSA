class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        vector<int> leftSumArr(n, 0);
        vector<int> ans(n, 0);

        for (int i = 1; i < n; i++) {
            leftSumArr[i] = leftSumArr[i - 1] + nums[i - 1];
        }

        int rightSum = 0;

        for (int i = n - 1; i >= 0; i--) {
            ans[i] = abs(leftSumArr[i] - rightSum);
            rightSum += nums[i];
        }

        return ans;
    }
};