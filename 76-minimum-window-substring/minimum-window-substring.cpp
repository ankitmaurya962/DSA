class Solution {
public:
    string minWindow(string s, string t) {
        int n = t.size();
        int minLen = INT_MAX;
        int startIdx = -1;
        int l = 0;
        int r = 0;

        unordered_map<char, int> mp;

        for (int i = 0; i < t.size(); i++) {
            mp[t[i]]++;
        }

        int count = 0;

        while(r < s.size()){
            
            if(mp[s[r]] > 0) count++;
            mp[s[r]]--;

            while(count == n){
                
                if(minLen > r - l + 1){
                    minLen = r - l + 1;
                    startIdx = l;
                }

                mp[s[l]]++;

                if(mp[s[l]] > 0) count--;
                l++;
            }
            r++;
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};
