class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int maxLight = lights[0];

        for(auto it: lights) maxLight = max(maxLight, it);

        int minPen = 0;
        for(int i = 0; i<arrivalTime.size(); i++){
            int r = arrivalTime[i] % period;

            if(r >= maxLight){
                minPen = max(minPen, period - r);
            }
        }

        return minPen;
    }
};