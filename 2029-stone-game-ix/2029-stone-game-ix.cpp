class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        // Count frequencies of remainders when divided by 3
        vector<int> cnt(3, 0);
        for (int stone : stones) {
            cnt[stone % 3]++;
        }

        // Case 1: Even number of trailing zeros
        if (cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        }

        // Case 2: Odd number of trailing zeros
        return abs(cnt[1] - cnt[2]) > 2;
    }
};
