class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> score(n,0);
        score[n-1] = nums[n-1];
        for(int i = n-2;i>=0;i--){
            score[i] = min(score[i+1],nums[i]);
        }

        int maxi = nums[0];
        for(int i = 0;i<n;i++){
            maxi = max(maxi,nums[i]);
            if(maxi - score[i]<=k) return i;
        }

        return -1;
    }
};