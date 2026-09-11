class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //adjacency list
        vector<vector<pair<int, int>>>adj(n+1);
        for(int i = 0; i<times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adj[u].push_back({v, w});
        }
 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

        pq.push({0, k});

        vector<int>dist(n + 1, INT_MAX);
        dist[k] = 0;

        while(!pq.empty()){
            int node = pq.top().second;
            int t = pq.top().first;
            pq.pop();

            for(auto it: adj[node]){
                int tm = it.second;

                if(tm + t < dist[it.first]){
                    dist[it.first] = tm + t;
                    pq.push({dist[it.first], it.first});
                }
            }
        }

        int maxTime = INT_MIN;
        for(int i = 1; i<=n; i++) maxTime = max(maxTime, dist[i]);

        return maxTime == INT_MAX ? -1 : maxTime;
    }
};