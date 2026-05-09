class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        vector<int> temp;

        // store first k elements
        for (int i = 0; i < k; i++) {
            temp.push_back(nums[i]);
        }

        // shift remaining elements left
        for (int i = 0; i < n - k; i++) {
            nums[i] = nums[i + k];
        }

        // place stored elements at end
        for (int i = 0; i < k; i++) {
            nums[n - k + i] = temp[i];
        }
    }
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int srow = 0, erow = grid.size() - 1, scol = 0,
            ecol = grid[0].size() - 1;
        vector<vector<int>> ans(grid.size(), vector<int>(grid[0].size(), 0));
        while (srow <= erow && scol <= ecol) {

            vector<int> temp;
            // top
            for (int i = scol; i <= ecol; i++) {
                temp.push_back(grid[srow][i]);
            }
            // right
            for (int i = srow + 1; i <= erow; i++) {
                temp.push_back(grid[i][ecol]);
            }
            // bottom
            for (int i = ecol - 1; i >= scol; i--) {
                if (srow == erow) {
                    break;
                }
                temp.push_back(grid[erow][i]);
            }
            // left
            for (int i = erow - 1; i > srow; i--) {
                if (scol == ecol) {
                    break;
                }
                temp.push_back(grid[i][scol]);
            }

            rotate(temp, k);
            // pasting to original
            //  top
            int j = 0;
            for (int i = scol; i <= ecol; i++) {
                grid[srow][i] = temp[j++];
            }
            // right
            for (int i = srow + 1; i <= erow; i++) {
                grid[i][ecol] = temp[j++];
            }
            // bottom
            for (int i = ecol - 1; i >= scol; i--) {
                if (srow == erow) {
                    break;
                }
                grid[erow][i] = temp[j++];
            }
            // left
            for (int i = erow - 1; i > srow; i--) {
                if (scol == ecol) {
                    break;
                }
                grid[i][scol] = temp[j++];
            }
            srow++, erow--, scol++, ecol--;
        }
        return grid;
    }
};