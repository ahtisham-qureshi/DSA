class Solution {
    vector<vector<int>> dp;
    int n;
    int totalOps;
public:
    int solve(int i,int op,vector<int>& prices){
        if(i == n || op == totalOps) return 0;
        if(dp[i][op] != -1) return dp[i][op];

        if(op%2 == 0){
            return dp[i][op] = max(-prices[i] + solve(i+1,op+1,prices),solve(i+1,op,prices));
        }else{
            return dp[i][op] = max(prices[i] + solve(i+1,op+1,prices),solve(i+1,op,prices));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        totalOps = k*2;
        dp.assign(n,vector<int>(totalOps,-1));

        return solve(0,0,prices);
    }
};