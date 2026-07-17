class Solution {
    bool isPredecessor(string& longer, string& shorter) {
        if (longer.size() != shorter.size() + 1)
            return false;

        int i = 0, j = 0;

        while (i < longer.size()) {
            if (j < shorter.size() && longer[i] == shorter[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }

        return j == shorter.size();
    }

public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(),
             [](string& a, string& b) { return a.size() < b.size(); });
        int n = words.size();
        vector<int> dp(n, 1);

        int maxLen = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (isPredecessor(words[i], words[j]) && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
            maxLen = max(maxLen, dp[i]);
        }

        return maxLen;
    }
};