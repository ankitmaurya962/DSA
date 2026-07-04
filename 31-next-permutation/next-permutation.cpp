class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        //finding dip point
        int idx = -1;
        for(int i = n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                idx = i;
                break;
            }
        }
        //if there is no dip it means it is last permutation then first permuation will be return
        if(idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        //just greater element than dip point;
        for(int i = n-1; i>=0; i--){
            if(nums[i] > nums[idx]){
                swap(nums[i], nums[idx]);
                break;
            }
        }

        //sort remaining right part of dip point in ascending
        //used reverse as all element on right will be already sorted in descending order
        reverse(nums.begin()+idx + 1, nums.end());
    }
};