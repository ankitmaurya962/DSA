class Solution {
public:
    void f(int k, int idx, vector<int> temp, vector<vector<int>>& ans,
           int target) {
        if (idx > 9) {
            if (target == 0 && temp.size() == k)
                ans.push_back(temp);
            return;
        }

        if (target == 0 && temp.size() == k) {
            ans.push_back(temp);
        }

        for (int i = idx; i <= 9; i++) {
            if (temp.size() < k) {
                temp.push_back(i);
                f(k, i + 1, temp, ans, target - i);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;

        f(k, 1, temp, ans, n);

        return ans;
    }
};