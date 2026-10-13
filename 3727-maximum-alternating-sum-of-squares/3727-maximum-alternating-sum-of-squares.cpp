class Solution {
public:
    static bool sqrSort(int x, int y) {
        return 1LL * x * x > 1LL * y * y;
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end(), sqrSort);

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            if (i < (n + 1) / 2) {
                ans += 1LL * nums[i] * nums[i];
            } else {
                ans -= 1LL * nums[i] * nums[i];
            }
        }

        return ans;
    }
};