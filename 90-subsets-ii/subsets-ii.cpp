class Solution {
public:
    void func(set<vector<int>>& st, vector<int>& nums,
              int idx, vector<int>& temp) {

        if (idx == nums.size()) {
            st.insert(temp);
            return;
        }

        // Pick
        temp.push_back(nums[idx]);
        func(st, nums, idx + 1, temp);
        temp.pop_back();

        // Not pick
        func(st, nums, idx + 1, temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        func(st, nums, 0, temp);
        return vector<vector<int>>(st.begin(), st.end());
    }
};