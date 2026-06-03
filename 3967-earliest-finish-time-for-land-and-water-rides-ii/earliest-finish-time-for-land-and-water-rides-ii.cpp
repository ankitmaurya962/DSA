class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int min_land = INT_MAX;
        int min_time = INT_MAX;
        for(int i = 0; i<landStartTime.size(); i++){
            min_land = min(min_land, landStartTime[i] + landDuration[i]);
        }

        for(int i = 0; i<waterStartTime.size(); i++){
            min_time = min(min_time, max(min_land, waterStartTime[i]) + waterDuration[i]);
        }

        //water->land
        int min_water = INT_MAX;
        for(int i = 0; i<waterStartTime.size(); i++){
            min_water = min(min_water, waterStartTime[i] + waterDuration[i]);
        }

        for(int i = 0; i<landStartTime.size(); i++){
            min_time = min(min_time, max(min_water, landStartTime[i]) + landDuration[i]);
        }

        return min_time;
    }
};