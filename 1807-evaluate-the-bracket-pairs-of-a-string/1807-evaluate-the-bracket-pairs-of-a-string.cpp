class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.length();

        unordered_map<string, string> m;
        for (const auto& pair : knowledge) {
            m[pair[0]] = pair[1];
        }

        string ans = "";
        string key = "";
        bool open = false;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open = true;
            } else if (s[i] == ')') {
                if (m.find(key) == m.end()) {
                    ans += '?';
                } else {
                    ans += m[key];
                }
                key = "";
                open = false;
            } else if (open) {
                key += s[i];
            } else {
                ans += s[i];
            }
        }

        return ans;
    }
};