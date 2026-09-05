class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int minIdx = -1;
        int maxIdx = -1;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int n = nums.size();
        if(n == 1) return 1;

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] > maxi){
                maxi = nums[i];
                maxIdx = i;
            }

            if(nums[i] < mini){
                mini = nums[i];
                minIdx = i;
            }
        }

        int mindeletions = INT_MAX;
        int left = min(minIdx, maxIdx);
        int right = max(minIdx, maxIdx);

        //remove both from left
        int removeleft = right + 1;
        mindeletions = min(mindeletions, removeleft);
        //remove both from right
        int removeright = n - left;
        mindeletions = min(mindeletions, removeright);
        //remove both sides
        int removeboth = (left + 1) + (n-right);
        mindeletions = min(mindeletions, removeboth);

        return mindeletions;
    }
};