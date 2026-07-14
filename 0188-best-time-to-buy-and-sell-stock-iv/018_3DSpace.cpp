class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> ahead(2, vector<int>(k+1, 0)),curr(2, vector<int>(k+1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int count = 1; count <= k; count++) {
                curr[1][count] = max(-prices[i] + ahead[0][count], ahead[1][count]);
                curr[0][count] = max(prices[i] + ahead[1][count - 1],ahead[0][count]);
            }
            ahead = curr;
        }

        return ahead[1][k];
    }
};
