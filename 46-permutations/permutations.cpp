class Solution {
public:
    void f(vector<int>&nums, set<vector<int>>&st, int idx){
        if(idx == nums.size()){
            st.insert(nums);
            return;
        }
        for(int i = idx; i<nums.size(); i++){
            swap(nums[idx], nums[i]);
            f(nums, st, idx+1);
            swap(nums[idx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        set<vector<int>>st;
        f(nums, st, 0);
        vector<vector<int>>ans;
        for(auto it: st) ans.push_back(it);

        return ans;
    }
};