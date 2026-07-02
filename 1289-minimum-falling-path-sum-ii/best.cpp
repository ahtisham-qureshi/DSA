class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> dp = grid[n - 1];

        for (int i = n - 2; i >= 0; i--) {

            int firstMin = INT_MAX, secondMin = INT_MAX;
            int firstIndex = -1;

            // Find smallest and second smallest in dp
            for (int j = 0; j < n; j++) {
                if (dp[j] < firstMin) {
                    secondMin = firstMin;
                    firstMin = dp[j];
                    firstIndex = j;
                } else if (dp[j] < secondMin) {
                    secondMin = dp[j];
                }
            }

            vector<int> curr(n);

            for (int j = 0; j < n; j++) {
                if (j == firstIndex)
                    curr[j] = grid[i][j] + secondMin;
                else
                    curr[j] = grid[i][j] + firstMin;
            }

            dp = curr;
        }

        return *min_element(dp.begin(), dp.end());
    }
};
