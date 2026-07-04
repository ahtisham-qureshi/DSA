class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int total = 0;
        for(int i : stones) total += i;
        vector<bool> dp(total + 1,false);

       
        dp[0] = true;
        if(stones[0]<=total) dp[stones[0]] = true;

        for(int i = 1;i<n;i++){
            vector<bool> curr(total + 1,false);
            curr[0] = true;
            for(int j = 1;j<=total;j++){
                bool skip = dp[j];
                bool take = false;
                if(stones[i]<=j){
                    take = dp[j-stones[i]];
                }

                curr[j] = skip || take;
            }
            dp = curr;
        }


        int ans = 1e9;
        for(int i = 0;i<=total/2;i++){
            if(dp[i]){
                ans = min(ans,abs((total-i) - i));
            }
        }

        return ans;
    }
};