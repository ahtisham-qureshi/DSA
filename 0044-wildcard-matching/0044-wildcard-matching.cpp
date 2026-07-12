class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();

        vector<bool> prev(n + 1, false);

        prev[0] = true;
        for (int k = 1; k <= n; k++) {
            if (prev[k - 1] && p[k - 1] == '*')
                prev[k] = true;
        }

        for (int i = 1; i <= m; i++) {
            bool preDig= prev[0];
            prev[0] = false;
            for (int j = 1; j <= n; j++) {
                bool temp = prev[j];
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    prev[j] = preDig;
                } else if (p[j - 1] == '*') {
                    prev[j] = prev[j] || prev[j - 1];
                } else
                    prev[j] = false;
                preDig = temp;
            }
        }

        return prev[n];
    }
};