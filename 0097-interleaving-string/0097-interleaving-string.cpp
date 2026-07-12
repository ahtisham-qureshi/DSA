class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        int q = s3.length();
        if (m + n != q)
            return false;

        vector<bool> dp(n + 1, 0),curr(n+1,0);

        dp[0] = true;
        for (int j = 1; j <= n; j++) {
            dp[j] = dp[j - 1] && (s2[j - 1] == s3[j - 1]);
        }

        for (int i = 1; i <= m; i++) {
            curr[0] = dp[0] && (s1[i - 1] == s3[i - 1]);
            for (int j = 1; j <= n; j++) {
                int k = i + j - 1;

                curr[j] = (dp[j] && s1[i - 1] == s3[k]) ||
                           (curr[j - 1] && s2[j - 1] == s3[k]);
            }
            dp = curr;
        }

        return dp[n];
    }
};