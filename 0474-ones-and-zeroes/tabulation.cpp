class Solution {
    vector<vector<vector<int>>> dp;
    vector<pair<int, int>> cnt;

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int L = strs.size();
        dp.resize(L,
                  vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
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
                dp[0][j][k] = 1;
            }
        }

        for (int i = 1; i < L; i++) {
            int z = cnt[i].first;
            int o = cnt[i].second;
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {

                    int skip = dp[i - 1][j][k];
                    int take = 0;
                    if (j >= z && k >= o)
                        take = 1 + dp[i - 1][j - z][k - o];

                    dp[i][j][k] = max(skip, take);
                }
            }
        }

        return dp[L - 1][m][n];
    }
};
