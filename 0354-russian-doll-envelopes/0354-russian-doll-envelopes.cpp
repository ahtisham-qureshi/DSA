class Solution {
    static bool sortBool(const vector<int>& e1, const vector<int>& e2) {
        if (e1[0] == e2[0])
            return e1[1] > e2[1];
        return e1[0] < e2[0];
    }

public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), sortBool);

        vector<int> temp;

        for (auto &env : envelopes) {
            if (temp.empty() || env[1] > temp.back()) {
                temp.push_back(env[1]);
            } else {
                int ind = lower_bound(temp.begin(), temp.end(), env[1]) - temp.begin();
                temp[ind] = env[1];
            }
        }

        return temp.size();
    }
};