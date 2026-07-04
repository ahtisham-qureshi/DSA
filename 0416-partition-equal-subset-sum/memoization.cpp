class Solution {
    vector<vector<int>> dp;

    bool solve(int i, int target, vector<int>& nums) {
        if (target == 0) return true;
        if (i < 0) return false;

        if (dp[i][target] != -1)
            return dp[i][target];

        bool skip = solve(i - 1, target, nums);

        bool take = false;
        if (nums[i] <= target)
            take = solve(i - 1, target - nums[i], nums);

        return dp[i][target] = skip || take;
    }

public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if (total%2)
            return false;

        int target = total / 2;
        int n = nums.size();

        dp.assign(n, vector<int>(target + 1, -1));

        return solve(n - 1, target, nums);
    }
};
