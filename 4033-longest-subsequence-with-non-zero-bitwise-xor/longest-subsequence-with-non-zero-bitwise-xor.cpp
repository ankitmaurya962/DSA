class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

        int allxor = 0;

        for(int i = 0; i<nums.size(); i++){
            allxor ^= nums[i];
        }

        if(allxor != 0) return nums.size();

        for(int i = 0; i<nums.size(); i++){
            int tempXor = allxor ^ nums[i];
            if(tempXor != 0) return nums.size()-1;
        }

        return 0;
    }
};