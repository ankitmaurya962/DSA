class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int countSub = 0;
        
        for(int i = 0; i<nums.size(); i++){
            int freq = 0;
            for(int j = i; j<nums.size(); j++){
                if(nums[j] == target) freq++;

                int l = j-i+1;
                if(freq > l/2) countSub++;
            }
        }
        return countSub;
    }
};