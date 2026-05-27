class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int>mp;
        
        int count = 0;
        for(int i=0; i<word.size(); i++){
            if(word[i]>='a' && word[i]<='z'){
                mp[word[i]] = i;
            }else{
                if(mp.find(word[i])==mp.end()){
                    mp[word[i]] = i;
                }
            }
        }
        for(auto it: mp){
            if(it.first>='A' && it.first<='Z'){
                if(mp.find(it.first + 32)!=mp.end()){
                    if(mp[it.first]>mp[it.first + 32]){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};