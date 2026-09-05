class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>preMax(n);
        vector<int>preMin(n);
        preMax[0] = nums[0];
        preMin[n-1] = nums[n-1];
        int maxi = nums[0];
        int mini = nums[n-1];
        for(int i = 1; i<n; i++){
            maxi = max(nums[i], maxi);
            preMax[i] = maxi;
        }
        for(int i = n-2; i>=0; i--){
            mini = min(nums[i], mini);
            preMin[i] = mini;
        }
        
        for(int i = 0; i<n; i++){
            int s = preMax[i] - preMin[i];
            if(s<=k){
                return i;
            }
        }

        return -1;
    }
};