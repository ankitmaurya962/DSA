class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        queue<vector<int>> q;
        vector<vector<vector<int>>>vis(n, vector<vector<int>>(m, vector<int>(k+1, false)));

        q.push({0, 0, k});
        vis[0][0][k] = true;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        int steps = 0;
      
        while (!q.empty()) {
            int s = q.size();

            for (int i = 0; i < s; i++) {
                vector<int> temp = q.front();
                q.pop();

                int r = temp[0];
                int c = temp[1];
                int obs = temp[2];

                if (r == n - 1 && c == m - 1)
                    return steps;

                for (int j = 0; j < 4; j++) {
                    int new_r = r + drow[j];
                    int new_c = c + dcol[j];

                    if(new_r >=0 && new_r < n && new_c >= 0 && new_c < m && !vis[new_r][new_c][obs] && grid[new_r][new_c] == 0){
                        vis[new_r][new_c][obs] = true;
                        q.push({new_r, new_c, obs});
                    }else if( new_r >=0 && new_r < n && new_c >= 0 && new_c < m && obs > 0 && !vis[new_r][new_c][obs-1] && grid[new_r][new_c] == 1){
                        vis[new_r][new_c][obs-1] = true;
                        q.push({new_r, new_c, obs-1});
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};