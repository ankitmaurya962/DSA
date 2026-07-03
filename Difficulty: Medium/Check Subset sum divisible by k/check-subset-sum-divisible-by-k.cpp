class Solution {
public:
    vector<vector<int>> dp;

    bool subset(vector<int>& arr, int idx, int rem, int k, bool taken) {

        if (taken && rem == 0)
            return true;

        if (idx == arr.size())
            return false;

        if (dp[idx][rem] != -1)
            return dp[idx][rem];

        // Don't take current element
        if (subset(arr, idx + 1, rem, k, taken))
            return dp[idx][rem] = true;

        // Take current element
        int newRem = (rem + arr[idx]) % k;
        if (subset(arr, idx + 1, newRem, k, true))
            return dp[idx][rem] = true;

        return dp[idx][rem] = false;
    }

    bool divisibleByK(vector<int>& arr, int k) {
        dp.assign(arr.size(), vector<int>(k, -1));
        return subset(arr, 0, 0, k, false);
    }
};