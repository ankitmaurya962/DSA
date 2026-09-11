class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>>adj(n);

        for(int i = 0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        priority_queue<pair<double, int>>pq;
        vector<double>dist(n, 0.0);
        dist[start_node] = 1.0;
        pq.push({1.0, start_node});

        while(!pq.empty()){
            int node = pq.top().second;
            double wt = pq.top().first;
            pq.pop();

            for(auto it: adj[node]){
                double w = it.second;
                if(wt * w > dist[it.first]){
                    dist[it.first] = wt * w;
                    pq.push({dist[it.first], it.first});
                }
            }
        }

        return dist[end_node];
    }
};