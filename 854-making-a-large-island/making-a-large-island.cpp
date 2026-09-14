class Solution {
public:
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};

    void dfs(int row, int col, vector<vector<int>>& grid, int id, int &size) {
        grid[row][col] = id;
        size++;
        for (int i = 0; i < 4; i++) {
            int newX = drow[i] + row;
            int newY = dcol[i] + col;

            if (newX >= 0 && newX < grid.size() && newY >= 0 &&
                newY < grid.size() && grid[newX][newY] == 1) {
                dfs(newX, newY, grid, id, size);
            }
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        unordered_map<int, int> mp;
        int id = 2;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int size = 0;
                    dfs(i, j, grid, id, size);
                    mp[id] = size;
                    id++;
                }
            }
        }

        int maxArea = 0;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) {
                    unordered_set<int>st;
                    for (int i = 0; i < 4; i++) {
                        int newX = drow[i] + row;
                        int newY = dcol[i] + col;

                        if (newX >= 0 && newX < grid.size() && newY >= 0 &&
                            newY < grid.size() && grid[newX][newY] !=0) {
                            st.insert(grid[newX][newY]);
                        }
                    }

                    int size = 1;
                    for(auto it: st){
                        size+= mp[it];
                    }

                    maxArea = max(size, maxArea);
                }
            }
        }

        return maxArea == 0 ? n*n : maxArea;
    }
};