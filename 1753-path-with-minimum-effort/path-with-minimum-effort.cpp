class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));

        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>> , greater<pair<int, pair<int,int>>>>pq;
        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        int row[] = {-1, 0, 1, 0};
        int col[] = {0, 1, 0, -1};

        while(!pq.empty()){
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int effort = pq.top().first;
            pq.pop();

            // if(x == n-1 && y == m-1) return effort;

            for(int i = 0; i<4; i++){
                int newX = row[i] + x;
                int newY = col[i] + y;

                if(newX >=0 && newX<n && newY>=0 && newY<m){
                    int newEffort = max(effort, abs(heights[x][y] - heights[newX][newY]));
                    
                    if(newEffort < dist[newX][newY]){
                        dist[newX][newY] = newEffort;
                        pq.push({newEffort, {newX, newY}});
                    }
                }
            }
        }
        return dist[n-1][m-1] == INT_MAX ? -1 : dist[n-1][m-1];
    }
};