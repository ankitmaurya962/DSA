class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if (nums.size() == 3)
            return nums[0] * nums[1] * nums[2];

        vector<bool> used(nums.size(), false);

        int largPos1 = INT_MIN, largPos2 = INT_MIN, largPos3 = INT_MIN;
        int idx = -1;

        // first largest
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > largPos1) {
                largPos1 = nums[i];
                idx = i;
            }
        }
        used[idx] = true;

        // second largest
        idx = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i] && nums[i] > largPos2) {
                largPos2 = nums[i];
                idx = i;
            }
        }
        used[idx] = true;

        // third largest
        idx = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i] && nums[i] > largPos3) {
                largPos3 = nums[i];
                idx = i;
            }
        }

        vector<bool> usedNeg(nums.size(), false);

        int largNeg1 = INT_MAX, largNeg2 = INT_MAX;

        // smallest (most negative)
        idx = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < largNeg1) {
                largNeg1 = nums[i];
                idx = i;
            }
        }
        usedNeg[idx] = true;

        // second smallest
        idx = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (!usedNeg[i] && nums[i] < largNeg2) {
                largNeg2 = nums[i];
                idx = i;
            }
        }

        if (largNeg1 == INT_MAX || largNeg2 == INT_MAX)
            return largPos1 * largPos2 * largPos3;

        return max(largNeg1 * largNeg2 * largPos1,
                   largPos1 * largPos2 * largPos3);
    }
};