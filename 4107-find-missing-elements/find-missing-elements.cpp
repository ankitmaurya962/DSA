class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(), nums.end());

        int j = 0;
        for(int i = nums[0]; i<=nums[nums.size()-1]; i++){
            if(i != nums[j]){
                ans.push_back(i);
                continue;
            }
            j++;
        }

        return ans;
    }
};