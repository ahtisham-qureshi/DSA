class Solution {
    int n;
    vector<unordered_map<int,int>> dp;
public:
    int solve(int i,vector<int>& nums, int target){
        if(i == n){
            if(target == 0) return 1;
            return 0;
        }
        if(dp[i].count(target)) return dp[i][target];

        int plus = solve(i+1,nums,target-nums[i]);
        int minus = solve(i+1,nums,target+nums[i]);

        return dp[i][target] = plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        dp.resize(n,unordered_map<int,int>());

        return solve(0,nums,target);
    }
};