class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> dp(target + 1, 0);
        dp[target] = 1;

        for (int i = target - 1; i >= 0; i--) {
            int count = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (i + nums[j] <= target)
                    count += dp[i + nums[j]];
            }
            dp[i] = count;
        }

        return (int)dp[0];
    }
};