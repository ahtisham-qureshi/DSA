class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int total = 0;
        for (int i : nums)
            total += i;

        if (abs(target) > total)
            return 0;

        if ((total + target) % 2)
            return 0;

        int req = (total + target) / 2;

        vector<int> dp(req + 1, 0);

        dp[0] = 1;

        for (int num : nums) {
            for (int sum = req; sum >= num; sum--) {
                dp[sum] += dp[sum - num];
            }
        }

        return dp[req];
    }
};