class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();

        int ans = 0;
        int j = 0;
        vector<int> freq(26, 0);
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            while (freq[idx] >= 2) {
                freq[s[j] - 'a']--;
                j++;
            }

            freq[idx]++;
            ans = max(ans, i - j + 1);
        }

        return ans;
    }
};