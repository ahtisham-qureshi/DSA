class Solution {
    vector<vector<int>> dp;
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        dp.assign(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    continue;
                }

                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }

        return dp[m][n];
    }
public:
    int minDistance(string word1, string word2) {
        int lcs = longestCommonSubsequence(word1,word2);
        return (word1.length() + word2.length()) - 2*lcs;
    }
};