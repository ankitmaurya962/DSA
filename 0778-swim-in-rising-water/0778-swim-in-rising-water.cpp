class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>vis(n, vector<int>(n, 0));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({grid[0][0], {0, 0}});

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!pq.empty()){
            int time = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if(x == n-1 && y == n-1) return time;
            if(vis[x][y] == 1) continue;
            vis[x][y] = 1;

            for(int i = 0; i<4; i++){
                int newX = drow[i] + x;
                int newY = dcol[i] + y;

                if(newX >= 0 && newX < n && newY >=0 && newY < n && !vis[newX][newY]){
                    pq.push({max(time, grid[newX][newY]),{newX, newY}});
                }
            }
        }

        return -1;
    }
};