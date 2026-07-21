class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {

        s = "1" + s + "1";

        int totalOnes = 0;
        for (char c : s)
            if (c == '1') totalOnes++;

        int ans = totalOnes - 2;        // remove the 2 ones

        int n = s.size();

        vector<pair<int,int>> oneBlocks;
        vector<pair<int,int>> zeroBlocks;

        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;

            if (s[i] == '1')
                oneBlocks.push_back({i, j - 1});
            else
                zeroBlocks.push_back({i, j - 1});

            i = j;
        }

        // traverse every 1 block
        for (auto &block : oneBlocks) {

            int l = block.first;
            int r = block.second;

            
            if (l == 0 || r == n - 1) continue;
            if (s[l - 1] != '0' || s[r + 1] != '0') continue;

            int leftZero = 0, rightZero = 0;

            // count left zero block
            i = l - 1;
            while (i >= 0 && s[i] == '0') {
                leftZero++;
                i--;
            }

            // count right zero block
            i = r + 1;
            while (i < n && s[i] == '0') {
                rightZero++;
                i++;
            }

            ans = max(ans, totalOnes - 2 + leftZero + rightZero);
        }

        return ans;
    }
};