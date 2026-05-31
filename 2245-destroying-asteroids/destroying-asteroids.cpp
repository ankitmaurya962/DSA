class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        long long planetSize = mass;
        for(int i = 0; i<asteroids.size(); i++){
            if(asteroids[i]>planetSize) return false;

            planetSize += asteroids[i]; 
        }

        return true;
    }
};