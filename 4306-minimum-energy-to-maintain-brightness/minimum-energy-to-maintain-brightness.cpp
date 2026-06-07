class Solution {
public:
    int merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i<n; i++){
            if(ans.empty() || ans.back()[1]<intervals[i][0]){
                ans.push_back(intervals[i]);
            }
            else{
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        long long t = 0;
        for(int i = 0; i<ans.size(); i++){
            t += (ans[i][1] - ans[i][0]) + 1; 
        }

        return t;
    }
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        int time = merge(intervals);
        long long neededBulb = ceil(brightness/3.0);

        return neededBulb*time;
    }
};