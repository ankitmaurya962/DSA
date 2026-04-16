class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int smallest = INT_MAX;
        int n = words.size();
        for(int i = startIndex; i<n+startIndex; i++){
            if(words[i%n] == target){
                smallest = min(smallest, i-startIndex);
            }
        }
        for(int i = startIndex; i>startIndex-n; i--){
            if(words[(i + n) % n] == target){
                smallest = min(smallest, startIndex - i);
            }
        }

        return smallest == INT_MAX ? -1 : smallest;
    }
};