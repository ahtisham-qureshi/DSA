class Solution {
    vector<vector<int>> dp;
    int n;
public:
    int solve(int i,int last,vector<int>& nums){
        if(i == n) return 0;
        if(dp[i][last + 1] != -1) return dp[i][last + 1];

        int take = 0;
        if(last == -1 || nums[i]>nums[last]){
            take = 1 + solve(i+1,i,nums);
        }
        int notTake = solve(i+1,last,nums);

        return dp[i][last + 1] = max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        dp.assign(n,vector<int>(n + 1,-1));

        return solve(0,-1,nums);
    }
};