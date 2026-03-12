class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>>matrix(n, vector<int>(n, 1e9));

        for(int i = 0; i < n; i++) matrix[i][i] = 0;// for self distance

        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            matrix[u][v] = w;
            matrix[v][u] = w;
        }

        for(int via = 0; via<n; via++){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    if(matrix[i][via]!=1e9 && matrix[via][j]!=1e9){
                        matrix[i][j] = min(matrix[i][via] + matrix[via][j], matrix[i][j]);
                    }
                }
            }
        }
        int countcity = INT_MAX;
        int cityno = -1;
        for(int i = 0; i<n; i++){
            int count = 0;
            for(int j = 0; j<n; j++){
                if(i!=j && matrix[i][j]<=distanceThreshold){
                    count++;
                }
            }
            if(count <= countcity){
                countcity = count;
                cityno = i;
            }
        }
        return cityno;
    }
};