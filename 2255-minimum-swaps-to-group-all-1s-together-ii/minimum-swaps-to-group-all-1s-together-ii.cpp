class Solution
{
    public:
        int minSwaps(vector<int> &nums)
        {
            //count 1
            int window = 0;
            int originalSize = nums.size();
            for (int i = 0; i < originalSize; i++)
            {
                if (nums[i] == 1) window++;
            }
            //double the nums
            nums.reserve(originalSize *2);
            nums.insert(nums.end(), nums.begin(), nums.end());

            int count1 = 0;

            //first window
            for(int i = 0; i<window; i++){
                count1 += nums[i];
            }
            int minSwaps = window - count1;

            //for other window
            for (int i = window; i < originalSize + window; i++) {
                count1 += nums[i];
                count1 -= nums[i-window];
                minSwaps = min(minSwaps, window - count1);
            }
            return minSwaps;
        }
};