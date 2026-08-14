class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i = 0;
        int j = 0;
        int n = s.size();
        unordered_map<char, int>mp;
        int maxSub = 0;
        while(i < n){
            mp[s[i]]++;
            while(mp[s[i]] > 2){
                mp[s[j]]--;
                if(s[j] == 0) mp.erase(s[j]);
                j++;
            }

            maxSub = max(maxSub, i-j+1);
            i++;
        }

        return maxSub;
    }
};