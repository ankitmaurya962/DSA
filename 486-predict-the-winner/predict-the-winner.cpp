class Solution {
public:
    int f(int i, int j, vector<int>&nums){
        if(i > j) return 0;

        if(i == j) return nums[i];

        int takefirst = nums[i] + min(f(i+2, j, nums), f(i+1, j-1, nums));
        int takelast = nums[j] + min(f(i+1, j-1, nums), f(i, j-2, nums));

        return max(takefirst, takelast); 
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        
        for(auto it: nums) sum += it;

        int p1 = f(0, n-1, nums);
        int p2 = sum - p1;

        return p1 >= p2;
    }
};