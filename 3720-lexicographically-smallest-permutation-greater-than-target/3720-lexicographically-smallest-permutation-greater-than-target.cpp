class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> total(26, 0), prefix(26, 0);
        
        for (char c : s) total[c - 'a']++;
        
        // Find longest prefix matching target
        int matched = 0;
        for (int i = 0; i < n; ++i) {
            int idx = target[i] - 'a';
            if (total[idx] > prefix[idx]) {
                prefix[idx]++;
                matched++;
            } else {
                break;
            }
        }
        
        int div_idx = -1;
        char div_char = ' ';
        
        // Backtrack to find the rightmost divergence point
        for (int i = matched; i >= 0; --i) {
            while (matched > i) {
                prefix[target[--matched] - 'a']--;
            }
            if (i == n) continue;
            
            // Find smallest available character strictly greater than target[i]
            for (int c = (target[i] - 'a') + 1; c < 26; ++c) {
                if (total[c] - prefix[c] > 0) {
                    div_idx = i;
                    div_char = 'a' + c;
                    break;
                }
            }
            if (div_idx != -1) break;
        }
        
        if (div_idx == -1) return "";
        
        // Reconstruct string
        string ans = "";
        ans.reserve(n);
        
        for (int i = 0; i < div_idx; ++i) {
            ans.push_back(target[i]);
            total[target[i] - 'a']--;
        }
        
        ans.push_back(div_char);
        total[div_char - 'a']--;
        
        for (int i = 0; i < 26; ++i) {
            while (total[i]-- > 0) {
                ans.push_back('a' + i);
            }
        }
        
        return ans;
    }
};
