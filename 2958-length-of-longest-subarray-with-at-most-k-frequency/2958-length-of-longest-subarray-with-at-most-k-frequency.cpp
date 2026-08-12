class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> m;
        int ans = 0;
        int j = 0;
        for(int i = 0;i<n;i++){
            while(m[nums[i]] >= k){
                m[nums[j++]]--;
            }
            m[nums[i]]++;
            ans = max(ans,i-j+1);
        }

        return ans;
    }
};