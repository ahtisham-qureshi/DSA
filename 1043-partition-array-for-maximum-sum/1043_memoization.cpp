class Solution {
    int n;
    vector<int> dp;
public:
    int solve(int i, int k, vector<int>& arr) {
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];

        int maxEl = 0;
        int best = 0;
        for (int j = i; j < min(n, i + k); j++) {
            maxEl = max(maxEl, arr[j]);

            int len = j - i + 1;

            best = max(best, maxEl * len + solve(j + 1, k, arr));
        }

        return dp[i] = best;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        dp.assign(n,-1);

        return solve(0, k, arr);
    }
};
