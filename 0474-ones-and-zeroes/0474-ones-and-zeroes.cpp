class Solution {
    vector<vector<int>> dp;
    vector<pair<int, int>> cnt;

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int L = strs.size();
        dp.resize(m + 1, vector<int>(n + 1, 0));
        for (auto& s : strs) {
            int z = 0, o = 0;
            for (char c : s) {
                if (c == '0')
                    z++;
                else
                    o++;
            }
            cnt.push_back({z, o});
        }

        int z = cnt[0].first;
        int o = cnt[0].second;

        for (int j = z; j <= m; j++) {
            for (int k = o; k <= n; k++) {
                dp[j][k] = 1;
            }
        }

        for (int i = 1; i < L; i++) {
            int z = cnt[i].first;
            int o = cnt[i].second;
            for (int j = m; j >= z; j--) {
                for (int k = n; k >= o; k--) {
                    dp[j][k] = max(dp[j][k], 1 + dp[j - z][k - o]);
                }
            }
        }

        return dp[m][n];
    }
};