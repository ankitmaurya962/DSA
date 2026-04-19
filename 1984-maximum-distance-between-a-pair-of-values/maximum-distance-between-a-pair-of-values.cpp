class Solution
{
    public:
        int binarySearch(vector<int> &nums2, int low, int high, int target)
        {

            int ans = 0;
            while (low <= high)
            {
                int mid = low + (high - low) / 2;

                if (nums2[mid] < target)
                    high = mid - 1;

                if (nums2[mid] >= target){
                    low = mid + 1;
                    ans = mid;
                }else
                    high = mid - 1;
            }
            return ans;
        }
int maxDistance(vector<int> &nums1, vector<int> &nums2)
{
    int maxDiff = 0;
    int n = nums2.size();
    for (int i = 0; i < nums1.size(); i++)
    {
        int idx = binarySearch(nums2, i, n - 1, nums1[i]);
        maxDiff = max(maxDiff, idx - i);
    }

    return maxDiff;
}
};