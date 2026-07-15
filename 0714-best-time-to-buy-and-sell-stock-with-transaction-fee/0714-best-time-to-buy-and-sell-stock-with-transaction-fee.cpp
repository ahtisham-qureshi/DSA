class Solution {
    vector<vector<int>> dp;
    int n;
public:
    int solve(int i,bool j,vector<int>& prices,int fee){
        if(i == n) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(j){
            return dp[i][j] = max(-prices[i]+ solve(i+1,!j,prices,fee),solve(i + 1,j,prices,fee));
        }else{
            return dp[i][j] = max(prices[i] -fee + solve(i+1,!j,prices,fee),solve(i + 1,j,prices,fee));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        n = prices.size();
        dp.assign(n,vector<int>(2,-1));

        return solve(0,true,prices,fee);
    }
};