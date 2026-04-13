class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int mini = 0;
        bool firsttime = true;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == target && firsttime){
                mini = abs(i-start);
                firsttime = false;
            }else if(nums[i] == target && !firsttime){
                mini = min(abs(i - start), mini);
            }
        }
        return mini;
    }
};