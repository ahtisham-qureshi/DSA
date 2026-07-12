class Solution {

public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();

        vector<bool> prev(n + 1, false);

        prev[0] = true;
        for (int k = 2; k <= n; k += 2) {
            if (p[k - 1] == '*')
                prev[k] = prev[k - 2];
        }

        for (int i = 1; i <= m; i++) {
            bool prevDig = prev[0];
            prev[0] = false;
            for (int j = 1; j <= n; j++) {
                bool temp = prev[j];
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                    prev[j] = prevDig;
                } else if (p[j - 1] == '*') {
                    int match = (p[j - 2] == s[i - 1] || p[j - 2] == '.');
                    prev[j] = prev[j - 2] || (match && prev[j]);
                }else {
                    prev[j] = false;
                }

                prevDig = temp;
            }
        }

        return prev[n];
    }
};