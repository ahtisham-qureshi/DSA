class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> dp(n, 0);
        int maxi = 0;

        for (int i = 0; i < m; i++) {
            vector<int> curr(n,0);
            for (int j = 0; j < n; j++) {

                if (matrix[i][j] == '0')
                    curr[j] = 0;

                else if (i == 0 || j == 0)
                    curr[j] = 1;

                else
                    curr[j] = 1 + min({dp[j], curr[j-1], dp[j-1]});

                maxi = max(maxi, curr[j]);
            }
            dp = curr;
        }

        return maxi * maxi;
    }
};
