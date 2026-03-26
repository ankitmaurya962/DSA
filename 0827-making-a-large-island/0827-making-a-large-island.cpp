class Solution {
public:
    int find_parent(int i, vector<int>&parent){
        if(i == parent[i]) return i;

        return parent[i] = find_parent(parent[i], parent);
    }

    void Union(int x, int y, vector<int>&parent, vector<int>&Size){
        int parent_x = find_parent(x, parent);
        int parent_y = find_parent(y, parent);

        if(parent_x == parent_y) return;

        if(Size[parent_x] > Size[parent_y]){
            parent[parent_y] = parent_x;
            Size[parent_x] += Size[parent_y];
        }else{
            parent[parent_x] = parent_y;
            Size[parent_y] += Size[parent_x];
        }
    }


    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>parent(n*n);
        for(int i = 0; i<n*n; i++){
            parent[i] = i;
        }
        vector<int>Size(n*n, 1);

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    for(int k = 0; k<4; k++){
                        int newX = drow[k] + i;
                        int newY = dcol[k] + j;

                        if(newX >= 0 && newX < n && newY >= 0 && newY < n && grid[newX][newY] == 1){
                            int adjNode = n * newX + newY;
                            int node = n * i + j;
                            Union(adjNode, node, parent, Size);
                        }
                    }
                }
            }
        } 

        //traversing zeroes;
        int maxArea = 1;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 0){
                    set<int>UniqueParent;

                    for(int k = 0; k<4; k++){
                        int newX = drow[k] + i;
                        int newY = dcol[k] + j;

                        if(newX >= 0 && newX < n && newY >= 0 && newY < n && grid[newX][newY] == 1){
                            int adjNode = n * newX + newY;
                            UniqueParent.insert(find_parent(adjNode, parent));
                        }
                    }
                    int sum = 1;
                    for(auto it: UniqueParent){
                        sum += Size[it];
                    }
                    maxArea = max(sum, maxArea);
                }
            }
        }
        maxArea = max(maxArea, Size[find_parent(0, parent)]);
        return maxArea;       
    }
};