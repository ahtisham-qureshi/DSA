class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<tuple<int, int, int, int>> arr;

        for (int i = 0; i < n; i++) {
            int l = intervals[i][0];
            int r = intervals[i][1];
            int weight = intervals[i][2];

            arr.emplace_back(l, r, weight, i);
        }

        // Sort by ending time
        sort(arr.begin(), arr.end(),
             [](auto& a, auto& b) {
                 return get<1>(a) < get<1>(b);
             });

        // dp[i][j] = maximum score using first i intervals
        // and at most j intervals
        vector<vector<long long>> dp(n + 1, vector<long long>(5));

        // Store the indices producing dp[i][j]
        vector<vector<vector<int>>> indices(
            n + 1,
            vector<vector<int>>(5)
        );

        for (int i = 0; i < n; i++) {

            auto [l, r, weight, idx] = arr[i];

            // First interval whose end >= l
            // Therefore [0 ... k-1] have end < l
            int k = lower_bound(
                arr.begin(),
                arr.begin() + i,
                l,
                [](const tuple<int, int, int, int>& t, int val) {
                    return get<1>(t) < val;
                }
            ) - arr.begin();

            for (int j = 1; j <= 4; j++) {

                // Don't take current interval
                long long skip = dp[i][j];

                // Take current interval
                long long take = dp[k][j - 1] + weight;

                if (skip > take) {
                    dp[i + 1][j] = skip;
                    indices[i + 1][j] = indices[i][j];
                }
                else {
                    vector<int> cur = indices[k][j - 1];

                    cur.push_back(idx);

                    sort(cur.begin(), cur.end());

                    // Same score -> lexicographically smaller
                    if (skip == take) {
                        cur = min(cur, indices[i][j]);
                    }

                    dp[i + 1][j] = take;
                    indices[i + 1][j] = cur;
                }
            }
        }

        return indices[n][4];
    }
};