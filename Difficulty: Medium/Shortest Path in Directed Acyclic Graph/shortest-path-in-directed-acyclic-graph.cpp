class Solution {
  public:
  vector<int> topoSort(int V, vector<vector<int>>& edges) {
          vector<vector<int>> adj(V);

          for(int i = 0; i<edges.size(); i++){
              adj[edges[i][0]].push_back(edges[i][1]);
          }
          //creating indegree
          vector<int>indegree(V, 0);

          for(int i = 0; i<V; i++){
              for(auto it : adj[i]){
                  indegree[it]++;
              }
          }
          //making queue
          queue<int>q;

          for(int i = 0; i<V; i++){
              if(indegree[i] == 0){
                  q.push(i);
              }
          }
          //bfs
          vector<int>topo;
          while(!q.empty()){
              int node = q.front();
              topo.push_back(node);
              q.pop();

              for(auto it : adj[node]){
                  indegree[it]--;
                  if(indegree[it] == 0){
                      q.push(it);
                  }
              }
          }

          return topo;
      }
      
    vector<int> shortestPath(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>>adj(V);

                for(int i = 0; i<edges.size(); i++){
                    int u = edges[i][0];
                    int v = edges[i][1];
                    int w = edges[i][2];

                    adj[u].push_back({v, w});

                }

                vector<int>topo = topoSort(V, edges);

                vector<int>dist(V, INT_MAX);
                dist[0] = 0;
                for(auto node : topo){

                    // if(dist[node] == INT_MAX) continue;

                    for(auto it: adj[node]){
                        int w = it.second;
                        if(dist[node] != INT_MAX && dist[node] + w < dist[it.first]){
                            dist[it.first] = dist[node]+ w;
                        }
                    }
                }
                vector<int>ans(V, -1);
                for(int i = 0; i<dist.size(); i++){
                    if(dist[i]!=INT_MAX){
                        ans[i] = dist[i];
                    }
                }

                return ans;
    }
};
