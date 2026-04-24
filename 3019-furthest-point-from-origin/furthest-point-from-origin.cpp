class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int countSpaces = 0;
        int total = 0;

        for(int i = 0; i<moves.size(); i++){
            if(moves[i] == 'R') total++;
            else if(moves[i] == 'L') total--;
            else countSpaces++;
        }

        return total>0?total+countSpaces : abs(total - countSpaces);
    }
};