class Solution {
public:
    bool isPalindrome(string s, int st, int end){
        while(st<=end){
            if(s[st]!=s[end]){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
    void func(string s, vector<vector<string>>&ans, vector<string>palindrome, int idx, int n){
        if(idx == n){
            ans.push_back(palindrome);
            return;
        }

        for(int i = idx; i<n; i++){
            if(isPalindrome(s, idx, i)){
                palindrome.push_back(s.substr(idx, i-idx+1));
                func(s, ans, palindrome, i+1, n);
                palindrome.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>>ans;
        vector<string>palindrome;
        func(s, ans, palindrome, 0, n);
        return ans;
    }
};