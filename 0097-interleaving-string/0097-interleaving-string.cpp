class Solution {
    vector<vector<int>> dp;

public:
    int solve(int i, int j, string& s1, string& s2, string& s3) {
        if (i == 0 && j == 0)
            return true;

        int k = i + j - 1;

        if (dp[i][j] != -1)
            return dp[i][j];
        if (i>0 && s1[i - 1] == s3[k]) {
            if (solve(i - 1, j, s1, s2, s3))
                return dp[i][j] = true;
        }
        if (j>0 && s2[j-1] == s3[k]) {
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

        dp.assign(m + 1, vector<int>(n + 1, -1));
        return solve(m, n, s1, s2, s3);
    }
};