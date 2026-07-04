class Solution {
    vector<bool> dp;

public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if (total % 2)
            return false;

        int target = total / 2;
        int n = nums.size();

        dp.assign(target + 1, false);

        dp[0] = true;
        if (nums[0] <= target)
            dp[nums[0]] = true;
        for (int i = 1; i < n; i++) {
            vector<bool> curr(target + 1, false);
            curr[0] = true;
            for (int j = 1; j <= target; j++) {
                bool skip = dp[j];

                bool take = false;
                if (nums[i] <= j)
                    take = dp[j - nums[i]];

                curr[j] = skip || take;
            }
            dp = curr;
        }

        return dp[target];
    }
};