class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        vector<int>dp (n+1,0);
        int ans = 0;

        for(int i = 1;i<=m;i++){
            vector<int> curr(n+1,0);
            for(int j = 1;j<=n;j++){
                if(nums1[i-1] == nums2[j-1]){
                    curr[j] = dp[j-1] + 1;
                    ans = max(ans,curr[j]);
                }
            }
            dp = curr;
        }

        return ans;
    }
};