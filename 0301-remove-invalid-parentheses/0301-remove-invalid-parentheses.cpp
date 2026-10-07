class Solution {
    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') {
                count--;
                if (count < 0) return false;
            }
        }
        return count == 0;
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        if (s.empty()) return {""};

        queue<string> q;
        unordered_set<string> visited;

        q.push(s);
        visited.insert(s);
        bool found = false;

        while (!q.empty()) {
            int level_size = q.size();
            
            for (int i = 0; i < level_size; ++i) {
                string curr = q.front();
                q.pop();

                if (isValid(curr)) {
                    result.push_back(curr);
                    found = true;
                }

                if (found) continue;

                for (size_t j = 0; j < curr.length(); ++j) {
                    if (curr[j] != '(' && curr[j] != ')') continue;

                    string child = curr.substr(0, j) + curr.substr(j + 1);
                    
                    if (visited.find(child) == visited.end()) {
                        visited.insert(child);
                        q.push(child);
                    }
                }
            }

            if (found) break;
        }

        return result;
    }
};