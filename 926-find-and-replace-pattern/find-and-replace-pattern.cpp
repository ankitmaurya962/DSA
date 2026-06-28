class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;

        unordered_map<int, int>patternMap;

        for(int i = 0; i<pattern.size(); i++){
            patternMap[pattern[i]]++;
        }

        for(int i = 0; i<words.size(); i++){
            unordered_map<int, int>temp_map;
            for(int j = 0; j<pattern.size(); j++){
                temp_map[words[i][j]]++;
            }

            //compare freq AND first occurrence index
            int k = 0;
            while(k < pattern.size() && 
                  patternMap[pattern[k]] == temp_map[words[i][k]] && 
                  pattern.find(pattern[k]) == words[i].find(words[i][k])) {
                k++;
            }
            if(k == pattern.size()){
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};