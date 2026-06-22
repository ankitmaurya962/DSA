class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> map(26, 0);

        for (int i = 0; i < text.size(); i++) {
            map[text[i] - 'a']++;
        }

        string s = "balloon";
        int maxballon = INT_MAX;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            if (ch == 'b') {
                maxballon = min(map[ch - 'a'], maxballon);
            }
            else if (ch == 'a') {
                maxballon = min(map[ch - 'a'], maxballon);
            }
            else if (ch == 'l') {
                maxballon = min(map[ch - 'a'] / 2, maxballon);
            }
            else if (ch == 'o') {
                maxballon = min(map[ch - 'a'] / 2, maxballon);
            }
            else if (ch == 'n') {
                maxballon = min(map[ch - 'a'], maxballon);
            }
        }

        return maxballon;
    }
};