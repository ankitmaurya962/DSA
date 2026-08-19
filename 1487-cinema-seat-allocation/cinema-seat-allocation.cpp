class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, set<int>> mp;

        for (auto &it : reservedSeats) {
            mp[it[0] - 1].insert(it[1] - 1);
        }

        int count = (n - mp.size()) * 2;

        for (auto it : mp) {

            int k = 1;

            // first block: seats 2,3,4,5
            for (k; k <= 4; k++) {
                if (it.second.find(k) != it.second.end())
                    break;
            }

            if (k == 5) {
                count++;
            }
            else {
                // second block: seats 4,5,6,7
                k = 3;

                for (k; k <= 6; k++) {
                    if (it.second.find(k) != it.second.end())
                        break;
                }

                if (k == 7)
                    count++;
            }

            // third block: seats 6,7,8,9
            if (k != 7) {

                k = 5;

                for (k; k <= 8; k++) {
                    if (it.second.find(k) != it.second.end())
                        break;
                }

                if (k == 9)
                    count++;
            }
        }

        return count;
    }
};