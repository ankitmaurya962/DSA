class Solution {
public:
    double angleClock(int hour, int minutes) {
        double min_angle = minutes*6;
        double hoursWithMin = hour + double(minutes)/60;
        double hr_angle = hoursWithMin*30;

        double min_diff = min(abs(hr_angle - min_angle), 360 - abs(hr_angle - min_angle));
        return min_diff;
    }
};