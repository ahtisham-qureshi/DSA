class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ahead (n + 1,0),curr(n+1,0);

        for(int i = n - 1;i>=0;i--){
            for(int last = n;last>=0;last--){
                int take = 0;
                if(last == 0 || nums[i]>nums[last-1]){
                    take = 1 + ahead[i+1];
                }
                int notTake = ahead[last];

                curr[last] = max(take,notTake);
            }
            ahead = curr;
        }

        return ahead[0];
    }
};