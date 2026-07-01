class Solution {
    // bool isP = true;
public:
    int support(int i, string s, vector<int>& dp, int n) {
        if (i == n)
            return 1;

        if (s[i] == '0')
            return 0;

        if (dp[i] != -1) return dp[i];

        int ways = support(i + 1, s, dp, n);

        if (i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')))
            ways += support(i + 2, s, dp, n);

        return dp[i] = ways;
    }
    int numDecodings(string s) {
        int n = s.length();

        vector<int> dp(n, -1);

        return support(0, s, dp, n);
    }
};
