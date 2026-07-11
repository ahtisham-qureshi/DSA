class Solution {
    vector<int> dp;

public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        dp.assign(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            dp[i] = i;
        }

        for (int i = 1; i <= m; i++) {
            int preDig = dp[0];
            dp[0] = i;
            for (int j = 1; j <= n; j++) {
                int temp = dp[j];
                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = preDig;
                } else {
                    dp[j] = 1 + min({preDig, dp[j], dp[j - 1]});
                }
                preDig = temp;
            }
        }

        return dp[n];
    }
};