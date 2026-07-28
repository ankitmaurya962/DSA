class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        string r = s.substr(0, n/2);
        sort(r.begin(), r.end());
        string ans = r;
        if(n%2 !=0){
            ans += s[n/2];
        }
        reverse(r.begin(), r.end());
        ans += r;
        return ans;
    }
};