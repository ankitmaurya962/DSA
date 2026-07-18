class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int>allFreq(26, INT_MAX);
        for(int i = 0; i<words.size(); i++){
            vector<int>tempFreq(26, 0);
            for(int j = 0; j<words[i].size(); j++){
                tempFreq[words[i][j]-'a']++;
            }

            for(int j = 0; j<26; j++){
                allFreq[j] = min(allFreq[j], tempFreq[j]);
            }
        }

        vector<string>ans;

        for (int i = 0; i < 26; i++) {
            while (allFreq[i]--) {
                ans.push_back(string(1, 'a' + i));
            }
        }

        return ans;
    }
};