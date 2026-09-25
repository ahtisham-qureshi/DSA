class Solution {
public:
    set<string> solve(string s, int& i) {
        set<string> res;
        set<string> cur = {""};

        while (i < s.size() && s[i] != '}') {

            if (s[i] == '{') {
                i++; // skip {

                set<string> temp = solve(s, i);

                i++; // skip }

                set<string> next;

                for (auto& a : cur) {
                    for (auto& b : temp) {
                        next.insert(a + b);
                    }
                }

                cur = next;

            } 
            else if (s[i] == ',') {

                for (auto& x : cur)
                    res.insert(x);

                cur = {""};
                i++;

            } 
            else {

                set<string> next;

                for (auto& x : cur) {
                    next.insert(x + s[i]);
                }

                cur = next;

                i++;
            }
        }

        for (auto& x : cur)
            res.insert(x);

        return res;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;

        set<string> ans = solve(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};