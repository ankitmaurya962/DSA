class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int>arr;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                arr.push_back(grid[i][j]);
            }
        }

        sort(arr.begin(), arr.end());

        int target = arr[(arr.size()/2)];

        int oper = 0;
        for(int i = 0; i<arr.size(); i++){
            int need = abs(arr[i] - target);
            if(need%x == 0){
                oper += need/x;
            }else{
                return -1;
            }
        }

        return oper;
    }
};