class Solution {
    int n;
    vector<int> dp;

public:
    int solve(int i, vector<int>& stoneValue) {
        if (i >= n)
            return 0;
        if (dp[i] != INT_MIN)
            return dp[i];

        int sum = 0;
        int best = INT_MIN;

        for (int j = i; j < min(i + 3, n); j++) {
            sum += stoneValue[j];
            best = max(best, sum - solve(j + 1, stoneValue));
        }

        return dp[i] = best;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        dp.assign(n, INT_MIN);
        int ans = solve(0, stoneValue);
        if (ans > 0) {
            return "Alice";
        } else if (ans < 0) {
            return "Bob";
        } else {
            return "Tie";
        }
    }
};