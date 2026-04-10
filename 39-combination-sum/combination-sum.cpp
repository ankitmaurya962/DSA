class Solution {
public:
    void func(vector<vector<int>> &ans, vector<int>&temp, vector<int>&candidates, int target, int i){
        if(i == candidates.size()){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }
        //pick
        if(target >= candidates[i]){
            temp.push_back(candidates[i]);
            func(ans, temp, candidates, target - candidates[i], i);
            temp.pop_back();
        }

        //notPick
        func(ans, temp, candidates, target, i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        func(ans, temp, candidates, target, 0);

        return ans;
    }
};