class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0] == 1) return -1;
        if(n == 1 && m == 1) return 1;

        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 1;

        queue<pair<int, pair<int, int>>>q;
        q.push({1, {0, 0}});
        
        int drow[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dcol[8] = {0, 1, 1, 1, 0, -1, -1, -1};

        while(!q.empty()){
            int d = q.front().first;
            int X = q.front().second.first;
            int Y = q.front().second.second;
            q.pop();

            for(int i = 0; i<8; i++){
                int newX = drow[i] + X;
                int newY = dcol[i] + Y;

                if(newX >=0 && newX < n && newY < m && newY >=0 && grid[newX][newY] == 0){
                    if(d + 1 < dist[newX][newY]){
                        dist[newX][newY] = d+1;
                        q.push({dist[newX][newY], {newX, newY}});
                    }
                }
            }
        }

        return dist[n-1][m-1] == INT_MAX ? -1 : dist[n-1][m-1];
    }
};