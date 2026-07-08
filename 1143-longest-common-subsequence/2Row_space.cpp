class Solution {
    vector<int> dp;
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        dp.assign(n+1, 0);


        for (int i = 1; i <= m; i++) {
            vector<int> curr(n+1,0);
            for (int j = 1; j <= n; j++) {
                if (text1[i-1] == text2[j-1]) {
                    curr[j] = 1 + dp[j-1];
                    continue;
                }

                curr[j] = max(curr[j-1],dp[j]);
            }
            dp = curr;
        }

        return dp[n];
    }
};
