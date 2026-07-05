class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int total = 0;
        for(int i : nums) total += i;

        if (abs(target) > total)
            return 0;

        if ((total + target) % 2)
            return 0;

        int req = (total + target) / 2;
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(req + 1, 0));

        dp[n][0] = 1;

        for (int i = n-1; i >=0 ; i--) {

            for (int sum = 0; sum <= req; sum++) {

                dp[i][sum] = dp[i + 1][sum];

                if (nums[i] <= sum)
                    dp[i][sum] += dp[i + 1][sum - nums[i]];
            }
        }

        return dp[0][req];
    }
};