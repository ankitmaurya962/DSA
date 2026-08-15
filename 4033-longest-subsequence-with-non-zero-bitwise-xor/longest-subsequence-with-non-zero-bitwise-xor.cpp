class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

        int allxor = 0;

        int countZero = 0;
        for(int i = 0; i<nums.size(); i++){
            allxor ^= nums[i];
            if(nums[i] == 0) countZero ++;
        }

        if(allxor != 0) return nums.size();
        else{
            if(countZero == nums.size()) return 0;
        }

        return nums.size()-1;
    }
};