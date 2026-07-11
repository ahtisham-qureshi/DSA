class Solution {
    vector<int> dp;
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        dp.assign(n+1,0);

        for(int i = 0;i<=n;i++){
            dp[i] = i;
        }

        for(int i = 1;i<=m;i++){
            vector<int> curr(n+1,0);
            curr[0] = i;
            for(int j = 1;j<=n;j++){
                if(word1[i-1] == word2[j-1]){
                    curr[j] = dp[j-1];
                }else{
                    curr[j] = 1 + min({dp[j-1],dp[j],curr[j-1]});
                }
            }
            dp = curr;
        }

        return dp[n];
    }
};