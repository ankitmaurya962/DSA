class Solution {
public:
    vector<vector<char>> rotateBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();

        vector<vector<char>> ans(m, vector<char>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[j][n - 1 - i] = boxGrid[i][j];
            }
        }

        return ans;
    }

    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();

        for (int i = 0; i < n; i++) {

            int start = 0;

            for (int j = 0; j <= m; j++) {

                // obstacle or end of row
                if (j == m || boxGrid[i][j] == '*') {

                    sort(boxGrid[i].begin() + start,
                         boxGrid[i].begin() + j,
                         greater<char>());

                    start = j + 1;
                }
            }
        }

        return rotateBox(boxGrid);
    }
};