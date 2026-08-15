class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        bool isAllZero = true;
        for (int i : nums) {
            if (i == 0)
                continue;

            isAllZero = false;
            ans ^= i;
        }

        if (isAllZero)
            return 0;

        return ans == 0 ? n - 1 : n;
    }
};