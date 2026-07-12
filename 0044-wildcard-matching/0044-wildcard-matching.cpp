class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();

        vector<bool> prev(n + 1, false), curr(n+1,false);

        prev[0] = true;
        for (int k = 1; k <= n; k++) {
            curr[0] = false;
            if (prev[k - 1] && p[k - 1] == '*')
                prev[k] = true;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    curr[j] = prev[j - 1];
                } else if (p[j - 1] == '*') {
                    curr[j] = prev[j] || curr[j - 1];
                } else
                    curr[j] = 0;
            }
            prev = curr;
        }

        return prev[n];
    }
};