class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>targetIndices;
        for(int i=0;i<nums.size();i++){
            int Find=target-nums[i];
            if(targetIndices.find(Find)!=targetIndices.end()){
                return {targetIndices[Find],i};
            }
            targetIndices[nums[i]]=i;
        }
        return {-1,-1};
    }
};