class Solution {
    int n;
    vector<vector<int>> dp;
public:
    int solve(int i,bool buy,vector<int>& prices){
        if(i == n){
            return 0;
        }

        if(dp[i][buy] != -1) return dp[i][buy];

        if(buy){
            return dp[i][buy] = max(-prices[i] + solve(i+1,false,prices),solve(i+1,true,prices));
        }else{
            return dp[i][buy] = max(prices[i] + solve(i+1,true,prices),solve(i+1,false,prices));
        }
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.assign(n,vector<int>(2,-1));

        return solve(0,true,prices);
    }
};