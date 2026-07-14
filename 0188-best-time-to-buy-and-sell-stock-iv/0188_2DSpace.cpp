class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        int totalOps = k * 2;
        vector<int> ahead(totalOps + 1, 0),curr(totalOps + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int op = totalOps - 1; op >= 0; op--) {
                if (op % 2 == 0) {
                    curr[op] =
                        max(-prices[i] + ahead[op + 1], ahead[op]);
                } else {
                    curr[op] =
                        max(prices[i] + ahead[op + 1], ahead[op]);
                }
            }
            ahead = curr;
        }

        return ahead[0];
    }
};
