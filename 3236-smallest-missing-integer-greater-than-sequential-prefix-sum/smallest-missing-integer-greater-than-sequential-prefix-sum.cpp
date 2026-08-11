class Solution {
public:
    int missingInteger(vector<int>& nums) {

        if(nums.size() == 1) return nums[0]+1;
        int longestSqPref = nums[0];
        
        int i = 1;
        for(i; i<nums.size(); i++){
            if(nums[i] == nums[i-1] + 1){
                longestSqPref += nums[i];
            }else {
                break;
            }
        }
        unordered_map<int, int>mp;
        for(auto it: nums){
            mp[it]++;
        }

        
        int ans = longestSqPref;

        while (mp.find(ans) != mp.end()) {
            ans++;
        }

        return ans;
    }
};