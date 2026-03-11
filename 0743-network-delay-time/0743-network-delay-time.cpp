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
        
        vector<int>dist(n+1, INT_MAX);
        dist[k] = 0;
        queue<pair<int, int>>q;
        q.push({k, 0});

        while(!q.empty()){
            int node = q.front().first;
            int w = q.front().second;
            q.pop();

            for(auto it: adj[node]){
                int adjNode = it.first;
                int wt = it.second;

                if(dist[adjNode] > w +wt){
                    dist[adjNode] = w + wt;
                    q.push({adjNode, wt + w});
                }
            }
        }

        int ans = INT_MIN;
        for(int i = 1; i<=n; i++){
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};