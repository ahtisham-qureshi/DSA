class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int prevBuy = 0; 
        int prevSell = 0;

        for (int i = n - 1; i >= 0; i--) {
            int currBuy = max(-prices[i] + prevSell, prevBuy);
            int currSell = max(prices[i] + prevBuy, prevSell);

            prevBuy = currBuy;
            prevSell = currSell;
        }

        return prevBuy;
    }
};