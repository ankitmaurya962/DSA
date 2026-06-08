class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>ans;

        //less numbers
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]<pivot){
                ans.push_back(nums[i]);
            }
        }
        //equal elements
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == pivot){
                ans.push_back(nums[i]);
            }
        }
        //greater elements
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] > pivot){
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
};