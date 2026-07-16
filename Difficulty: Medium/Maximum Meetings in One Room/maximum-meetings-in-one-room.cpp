class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b) {
        if (a[1] == b[1])
            return a[2] < b[2];   // If finish times are equal, smaller index first
        return a[1] < b[1];       // Sort by finish time
    }

    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        vector<vector<int>> meetings;

        // {start, finish, index}
        for (int i = 0; i < s.size(); i++) {
            meetings.push_back({s[i], f[i], i + 1});
        }

        sort(meetings.begin(), meetings.end(), comp);

        vector<int> ans;
        ans.push_back(meetings[0][2]);
        
        vector<int>lastMeeting = meetings[0];

        for (int i = 1; i < meetings.size(); i++) {
            if(meetings[i][0] > lastMeeting[1]){
                ans.push_back(meetings[i][2]);
                lastMeeting = meetings[i];
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};