class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int sumGain = 0;
        int maxPeak = 0;
        for(int i = 0; i<gain.size(); i++){
            sumGain += gain[i];
            maxPeak = max(maxPeak, sumGain);
        }

        return maxPeak;
    }
};