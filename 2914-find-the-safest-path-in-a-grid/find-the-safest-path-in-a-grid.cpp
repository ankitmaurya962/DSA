class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        queue<pair<int, int>>q;

        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[i].size(); j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                }
            }
        }

        //dfs to get safety factor
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i = 0; i<4; i++){
                int newX = x + drow[i];
                int newY = y + dcol[i];

                if(newX >=0 && newX < grid.size() && newY >= 0 && newY < grid.size() && grid[newX][newY] == 0){
                    grid[newX][newY] = grid[x][y] + 1;
                    q.push({newX, newY});
                }
            }
        }

        //traversing to grid to find min safest path from(0, 0) -> (n-1, n-1);
        priority_queue<vector<int>> pq;
        pq.push({grid[0][0], 0, 0});
        grid[0][0] = -1;

        while(!pq.empty()){
            int x = pq.top()[1];
            int y = pq.top()[2];
            int sfac = pq.top()[0];
            pq.pop();

            if(x == grid.size()-1 && y == grid.size()-1){
                return sfac - 1;
            }

            for(int i = 0; i<4; i++){
                int newX = x + drow[i];
                int newY = y + dcol[i];

                if(newX >=0 && newX < grid.size() && newY >= 0 && newY < grid.size() && grid[newX][newY] != -1){
                    int mini = min(sfac, grid[newX][newY]);
                    pq.push({mini, newX, newY});
                    grid[newX][newY] = -1;
                }
            }
        }
        return 0;
    }
};