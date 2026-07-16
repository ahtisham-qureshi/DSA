class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> dp(n,1),hash(n,0);

        int maxi = 1;
        int lastInd = 0;
        for(int i = 0;i<n;i++){
            hash[i] = i;
            for(int j = 0;j<i;j++){
                if(nums[i] % nums[j] == 0 && dp[i]<dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if(maxi<dp[i]){
                maxi = dp[i];
                lastInd = i;
            }
        }

        vector<int> answer;
        answer.push_back(nums[lastInd]);
        while(hash[lastInd] != lastInd){
            lastInd = hash[lastInd];
            answer.push_back(nums[lastInd]);
        }

        return answer;
    }
};