class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        char currDir = 'N';
        int x = 0, y = 0;
        int maxDist = 0;

        set<pair<int,int>>st;

        for(int i = 0; i<obstacles.size(); i++){
            st.insert({obstacles[i][0], obstacles[i][1]});
        }
        for(int i = 0; i < commands.size(); i++){

            if(commands[i] == -2){ // left turn
                if(currDir == 'N') currDir = 'W';
                else if(currDir == 'W') currDir = 'S';
                else if(currDir == 'S') currDir = 'E';
                else currDir = 'N';
            }
            else if(commands[i] == -1){ // right turn
                if(currDir == 'N') currDir = 'E';
                else if(currDir == 'E') currDir = 'S';
                else if(currDir == 'S') currDir = 'W';
                else currDir = 'N';
            }
            else {
                // move step by step
                for(int step = 0; step < commands[i]; step++){
                    int nx = x, ny = y;

                    if(currDir == 'N') ny++;
                    else if(currDir == 'S') ny--;
                    else if(currDir == 'E') nx++;
                    else nx--;

                    if(st.find({nx, ny})!=st.end()) break;

                    x = nx;
                    y = ny;

                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }

        return maxDist;
    }
};