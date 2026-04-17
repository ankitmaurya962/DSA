class Solution {
public:
    void func(vector<vector<int>>&ans, vector<int>&candidates, int idx, int target, vector<int>&temp){
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        for(int i = idx; i<candidates.size(); i++){
            if(i>idx && candidates[i] == candidates[i-1]) continue;

            if(target < candidates[i]) break;

            temp.push_back(candidates[i]);
            func(ans, candidates, i+1, target - candidates[i], temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;

        sort(candidates.begin(), candidates.end());
        func(ans, candidates, 0, target, temp);

        return ans;
    }
};