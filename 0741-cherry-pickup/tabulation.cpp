class Solution {
    int n;
    vector<vector<vector<int>>> dp;
public:
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        dp.resize(n, vector<vector<int>>(n, vector<int>(n, -1e9)));
        dp[n - 1][n - 1][n - 1] = grid[n - 1][n - 1];

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                for (int b = n - 1; b >= 0; b--) {
                    if (i == n - 1 && j == n - 1 && b == n - 1)
                        continue;
                    int a = i + j - b;
                    if (a < 0 || a >= n || grid[i][j] == -1 ||
                        grid[a][b] == -1) {
                        dp[i][j][b] = -1e9;
                        continue;
                    }

                    int downDown =
                        (i + 1 < n && a + 1 < n) ? dp[i + 1][j][b] : -1e9;
                    int downRight =
                        (i + 1 < n && b + 1 < n) ? dp[i + 1][j][b + 1] : -1e9;
                    int rightDown =
                        (j + 1 < n && a + 1 < n) ? dp[i][j + 1][b] : -1e9;
                    int rightRight =
                        (j + 1 < n && b + 1 < n) ? dp[i][j + 1][b + 1] : -1e9;

                    int curr = (j == b && a == i) ? grid[i][j]
                                                  : (grid[i][j] + grid[a][b]);

                    int best =
                        max({downDown, downRight, rightDown, rightRight});

                    if (best == -1e9)
                        dp[i][j][b] = -1e9;
                    else
                        dp[i][j][b] = curr + best;
                }
            }
        }

        return max(0, dp[0][0][0]);
    }
};
