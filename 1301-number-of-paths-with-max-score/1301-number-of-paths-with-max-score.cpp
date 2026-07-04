class Solution {
    vector<pair<int, int>> dp;
    const int MOD = 1e9 + 7;
    const pair<int, int> INVAL = {-1e9, 0};

public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        dp.resize(n, INVAL);

        for (int i = 0; i < n; i++) {
            vector<pair<int,int>> temp(n,INVAL);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    temp[j] = {0, 1};
                    continue;
                }
                if (board[i][j] == 'X') {
                    temp[j] = INVAL;
                    continue;
                }

                pair<int, int> up = (i - 1 < 0) ? INVAL : dp[j];
                pair<int, int> left = (j - 1 < 0) ? INVAL : temp[j - 1];
                pair<int, int> upLeft =
                    (i - 1 < 0 || j - 1 < 0) ? INVAL : dp[j - 1];

                int curr = (board[i][j] == 'S') ? 0 : board[i][j] - '0';
                int best = max({up.first, left.first, upLeft.first});

                if (best == INVAL.first) {
                    temp[j] = INVAL;
                    continue;
                }

                int path = 0;

                if (best == up.first) {
                    path = (path + up.second) % MOD;
                }
                if (best == left.first) {
                    path = (path + left.second) % MOD;
                }
                if (best == upLeft.first) {
                    path = (path + upLeft.second) % MOD;
                }

                temp[j] = {curr + best, path};
            }
            dp = temp;
        }

        if (dp[n - 1].first < 0)
            return {0, 0};
        return {dp[n - 1].first, dp[n - 1].second};
    }
};