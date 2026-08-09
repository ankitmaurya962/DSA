class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end(), greater<int>());
        sort(discounts.begin(), discounts.end(), greater<int>());

        int i = 0;
        int j = 0;

        double total = 0;
        for(i; i<discounts.size(); i++){
            if(j < prices.size()) total += (double)(prices[j] * (100 - discounts[i]))/100;
            j++;
        }

        for(j; j<prices.size(); j++){
            total += prices[j];
        }

        return total;
    }
};