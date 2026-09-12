class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>>adj(n);

        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, w});
                adj[j].push_back({i, w});
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, 0});

        vector<int>vis(n, 0);
        int sum = 0;
        while(!pq.empty()){
            int w = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(vis[node] == 1) continue;

            vis[node] = 1;
            sum += w;

            for(auto it: adj[node]){
                int child = it.first;
                int wt = it.second;
                if(vis[child] == 0){
                    pq.push({wt, child});
                }
            }
        }

        return sum;
    }
};