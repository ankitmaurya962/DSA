class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int minidx = -1;
        int minDis = INT_MAX;
        for(int i = 0; i<drones.size(); i++){
            int x = drones[i][0];
            int y = drones[i][1];
            int r = drones[i][2];

            int dist = abs(x - target[0]) + abs(y - target[1]);
            if(dist <=r && dist < minDis){
               minidx = i;
               minDis = dist;
            }
        }

        return minidx;
    }
};