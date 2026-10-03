class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>occur(3);
        int ans = 0;
        int l = 0;
        for(int i = 0; i<s.size(); i++){
            occur[s[i]-'a']++;
            
            while(occur[0] > 0 && occur[1] > 0 && occur[2] > 0){
                ans += s.size() - i;
                occur[s[l]-'a']--;
                l++;
            }
        }
        return ans;
    }
};