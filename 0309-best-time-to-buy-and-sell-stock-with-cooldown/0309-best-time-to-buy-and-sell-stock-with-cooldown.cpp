class Solution {
    vector<vector<int>> dp;
    int n;
public:
    int solve(int i,bool j,vector<int>& prices){
        if(i >= n) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(j){
            return dp[i][j] = max(-prices[i] + solve(i+1,!j,prices),solve(i + 1,j,prices));
        }else{
            return dp[i][j] = max(prices[i] + solve(i+2,!j,prices),solve(i + 1,j,prices));
        }
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.assign(n,vector<int>(2,-1));

        return solve(0,true,prices);
    }
};