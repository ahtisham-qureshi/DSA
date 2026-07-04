class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int total = 0;
        for(int i : stones) total += i;
        vector<vector<bool>> dp(n,vector<bool>(total + 1,false));

        for(int i = 0;i<n ;i++){
            dp[i][0] = true;
        }
        if(stones[0]<=total) dp[0][stones[0]] = true;

        for(int i = 1;i<n;i++){
            for(int j = 1;j<=total;j++){
                bool skip = dp[i-1][j];
                bool take = false;
                if(stones[i]<=j){
                    take = dp[i-1][j-stones[i]];
                }

                dp[i][j] = skip || take;
            }
        }


        int ans = 1e9;
        for(int i = 0;i<=total/2;i++){
            if(dp[n-1][i]){
                ans = min(ans,abs((total-i) - i));
            }
        }

        return ans;
    }
};
