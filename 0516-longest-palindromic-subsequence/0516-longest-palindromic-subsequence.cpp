class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int> dp(n, 1);

        for (int i = n - 2; i >= 0; i--) {
            int prevDiagonal = 0; 

            for (int j = i + 1; j < n; j++) {
                int temp = dp[j];

                if (s[i] == s[j]) {
                    dp[j] = 2 + prevDiagonal;
                } else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }

                prevDiagonal = temp;
            }
        }

        return dp[n - 1];
    }
};