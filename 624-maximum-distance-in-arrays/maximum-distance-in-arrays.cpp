class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxDist = 0;

        int f = arrays[0].size();
        int smallest = arrays[0][0];
        int largest = arrays[0][f-1];

        for(int i = 1; i<arrays.size(); i++){
            
            maxDist = max(maxDist, abs(largest - arrays[i][0]));
            int n = arrays[i].size();
            largest = max(largest, arrays[i][n-1]);
            maxDist = max(maxDist, abs(arrays[i][n-1] - smallest));
            smallest = min(smallest, arrays[i][0]);

        }

        return maxDist;
    }
};