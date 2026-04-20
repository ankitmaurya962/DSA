class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();

        int maxDis = 0;

        for(int i = n-1; i>0; i--){
            if(colors[i]!=colors[0]){
                maxDis = max(maxDis, i-0);
            } 
            if(colors[n-i]!=colors[n-1]){
                maxDis = max(maxDis, n-1-(n-i));
            } 
        }
        return maxDis;
    }
};