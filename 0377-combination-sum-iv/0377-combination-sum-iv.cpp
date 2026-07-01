class Solution {
public:
    int solve(int sum, vector<int>& dp, vector<int>& nums, int target) {
        if (sum > target)
            return 0;
        if (sum == target)
            return 1;
        if (dp[sum] != -1)
            return dp[sum];

        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += solve(sum + nums[i], dp, nums, target);
        }

        return dp[sum] = count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return solve(0, dp, nums, target);
    }
};