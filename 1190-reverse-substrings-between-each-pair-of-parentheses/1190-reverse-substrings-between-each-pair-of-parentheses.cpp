class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int> open;
        string ans = "";
        for (auto ch : s) {
            if (ch == '(') {
                open.push(ans.length());
            } else if (ch == ')') {
                int st = open.top();
                open.pop();

                reverse(ans.begin() + st, ans.end());
            } else {
                ans += ch;
            }
        }

        return ans;
    }
};