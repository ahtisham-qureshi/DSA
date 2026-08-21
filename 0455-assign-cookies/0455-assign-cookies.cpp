class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int j = 0;

        for (int cookie : s) {
            if (j < g.size() && cookie >= g[j]) {
                j++;
            }
        }

        return j;
    }
};