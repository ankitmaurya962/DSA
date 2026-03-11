class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        //adjacency list
        vector<vector<pair<int, int>>>adj(n);
        for(int i = 0; i<flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];

            adj[u].push_back({v, w});
        }

        vector<int>dist(n, INT_MAX);
        dist[src] = 0;
        queue<pair<int, int>>q;
        q.push({src, 0});
        int stops = 0;
        while(!q.empty() && stops<=k){
            int size = q.size();
            //traversing all nodes at same level
            while(size--){
                int node = q.front().first;
                int wt = q.front().second;
                q.pop();

                for(auto it: adj[node]){
                   int w = it.second;
                   if(w + wt < dist[it.first]){
                      dist[it.first] = w+wt;
                       q.push({it.first, w+wt});
                    }
                }
            }
            stops++;
        }
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};