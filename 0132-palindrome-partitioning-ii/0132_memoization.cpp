class Solution {
    vector<vector<int>> dp;

    bool isPalindrome(int l,int r,string& s){
        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }

        return true;
    }
public:
    int solve(int i, int j, string& s) {
        if (i >= j || isPalindrome(i,j,s))
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int best = 1e9;
        for (int k = i; k < j; k++) {
            if(isPalindrome(i,k,s))
                best = min(best, 1 + solve(k + 1, j, s));
        }

        return dp[i][j] = best;
    }
    int minCut(string s) {
        int n = s.length();
        dp.assign(n, vector<int>(n, -1));

        return solve(0, n - 1, s);
    }
};
