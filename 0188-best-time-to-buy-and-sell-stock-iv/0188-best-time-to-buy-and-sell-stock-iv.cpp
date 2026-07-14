class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int totalOps = k * 2;
        vector<int> ahead(totalOps + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int op = 0; op < totalOps; op++) {
                if (op % 2 == 0) {
                    ahead[op] =
                        max(-prices[i] + ahead[op + 1], ahead[op]);
                } else {
                    ahead[op] =
                        max(prices[i] + ahead[op + 1], ahead[op]);
                }
            }
        }

        return ahead[0];
    }
};