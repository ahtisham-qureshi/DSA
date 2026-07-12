class Solution {
    vector<vector<int>> dp;

public:
    int solve(int i, int j, string& s1, string& s2, string& s3) {
        int k = i + j + 1;
        if (i < 0) {
            for (int l = 0; l <= k; l++) {
                if (s2[l] != s3[l])
                    return false;
            }
            return true;
        }

        if (j < 0) {
            for (int l = 0; l <= k; l++) {
                if (s1[l] != s3[l])
                    return false;
            }
            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];
        if (s1[i] == s3[k]) {
            if (solve(i - 1, j, s1, s2, s3))
                return dp[i][j] = true;
        }
        if (s2[j] == s3[k]) {
            if (solve(i, j - 1, s1, s2, s3))
                return dp[i][j] = true;
        }

        return dp[i][j] = false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        int q = s3.length();
        if (m + n != q)
            return false;

        dp.assign(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, s1, s2, s3);
    }
};
