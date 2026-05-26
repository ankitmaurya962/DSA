class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int>mp;

        for(int i = 0; i<word.size(); i++){
            mp[word[i]]++;
        }

        int count = 0;

        for(int i = 0; i<word.size(); i++){
            if(word[i]>='a' && word[i]<='z'){
                if(mp.find(word[i]-32)!=mp.end()){
                    count++;
                    mp.erase(word[i]);
                    mp.erase(word[i]-32);
                }
            }
        }

        return count;
    }
};