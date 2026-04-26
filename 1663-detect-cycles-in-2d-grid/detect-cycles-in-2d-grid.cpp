class Solution {
public:
    bool dfs(vector<vector<char>>&grid, vector<vector<int>>&vis, int parX, int parY, int row, int col, int n, int m){
        vis[row][col] = 1;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        for(int i = 0; i<4; i++){
            int newR = row + drow[i];
            int newC = col + dcol[i];

            if(newR>=0 && newR<n && newC>=0 && newC < m && grid[newR][newC] == grid[row][col]){
                if(!vis[newR][newC]){
                    if (dfs(grid, vis, row, col, newR, newC, n, m))
                        return true;
                }
                else if(newR!=parX && newC!=parY){
                    return true;
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));

        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(vis[i][j] == 0){
                    if(dfs(grid, vis, -1, -1, i, j, n, m)){
                        return true;
                    }
                }
                
            }
        }
        return false;
    }
};