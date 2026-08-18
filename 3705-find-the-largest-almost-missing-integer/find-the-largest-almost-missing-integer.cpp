class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        // Only one subarray
        if (n == k)
            return *max_element(nums.begin(), nums.end());

        // k = 1
        if (k == 1) {
            unordered_map<int, int> freq;

            for (int x : nums)
                freq[x]++;

            int ans = -1;

            for (auto it : freq) {
                if (it.second == 1)
                    ans = max(ans, it.first);
            }

            return ans;
        }

        int first = nums[0];
        int last = nums[n - 1];

        int firstFreq = 0;
        int lastFreq = 0;

        for (int x : nums) {
            if (x == first)
                firstFreq++;

            if (x == last)
                lastFreq++;
        }

        int ans = -1;

        if (firstFreq == 1)
            ans = max(ans, first);

        if (lastFreq == 1)
            ans = max(ans, last);

        return ans;
    }
};