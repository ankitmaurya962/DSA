class Solution {
public:
    bool static comp(vector<int>temp1, vector<int>temp2){
        return temp1[1] - temp1[0] > temp2[1] - temp2[0];
    }

    bool isPossible(vector<vector<int>> &tasks, int leftEnergy){
        sort(tasks.begin(), tasks.end(), comp);

        for(int i = 0; i<tasks.size(); i++){
            if(tasks[i][1] > leftEnergy) return false;

            leftEnergy -= tasks[i][0];
        }

        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        int l = 0;
        int r = 1e9;

        int ans = INT_MAX;
        while(l<=r){
            
            int mid = l+(r-l)/2;

            if(isPossible(tasks, mid)){
                ans = min(ans, mid);
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        return ans;
    }
};