class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());

        int totalCost = 0;
        int count = 0;
        for(int i = 0; i<cost.size(); i++){
            if(count<2){
                count++;
                totalCost += cost[i];
            }
            else if(count == 2){
                count = 0;
            }
        }

        return totalCost;
    }
};