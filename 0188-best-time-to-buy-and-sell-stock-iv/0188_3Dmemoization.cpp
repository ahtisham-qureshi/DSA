class Solution {
    vector<vector<vector<int>>> dp;
    int n;
public:
    int solve(int i,bool buy,int count,vector<int>& prices){
        if(i == n || count == 0) return 0;
        if(dp[i][buy][count] != -1) return dp[i][buy][count];

        if(buy){
            return dp[i][buy][count] = max(-prices[i] + solve(i+1,false,count,prices),solve(i+1,true,count,prices));
        }else{
            return dp[i][buy][count] = max(prices[i] + solve(i+1,true,count-1,prices),solve(i+1,false,count,prices));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
         n = prices.size();
        dp.assign(n,vector<vector<int>>(2,vector<int>(k+1,-1)));

        return solve(0,1,k,prices);
    }
};
