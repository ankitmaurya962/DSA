class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int sum = 0;
        int maxRange = -1;

        for (int x : nums) {
            int num = x;
            int maxDigit = 0, minDigit = 9;

            if (num == 0) {
                maxDigit = minDigit = 0;
            }

            while (num > 0) {
                int digit = num % 10;
                maxDigit = max(maxDigit, digit);
                minDigit = min(minDigit, digit);
                num /= 10;
            }

            int range = maxDigit - minDigit;

            if (range > maxRange) {
                maxRange = range;
                sum = x;
            } else if (range == maxRange) {
                sum += x;
            }
        }

        return sum;
    }
};