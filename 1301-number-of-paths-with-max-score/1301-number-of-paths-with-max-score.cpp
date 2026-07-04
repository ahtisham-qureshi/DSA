class Solution {
    vector<vector<pair<int, int>>> dp;
    const int MOD = 1e9 + 7;

public:
    pair<int, int> solve(int i, int j, vector<string>& board) {
        if (i < 0 || j < 0 || board[i][j] == 'X')
            return {-1e9, 0};
        if (i == 0 && j == 0)
            return {0, 1};
        if (dp[i][j].first != -1)
            return dp[i][j];

        auto up = solve(i - 1, j, board);
        auto left = solve(i, j - 1, board);
        auto upLeft = solve(i - 1, j - 1, board);

        int curr = (board[i][j] == 'S' || board[i][j] == 'E') ? 0 : board[i][j] - '0';

        int best = max({up.first, left.first, upLeft.first});

        if (best == -1e9)
            return dp[i][j] = {-1e9, 0};

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

        return dp[i][j] = {curr + best, path};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        dp.resize(n, vector<pair<int, int>>(n, {-1, 0}));

        pair<int, int> ans = solve(n - 1, n - 1, board);
        if (ans.first < 0)
            return {0, 0};
        return {ans.first, ans.second};
    }
};