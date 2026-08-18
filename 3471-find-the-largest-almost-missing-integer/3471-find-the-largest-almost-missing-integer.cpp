class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        // Every element is in its own subarray
        if (k == 1) {
            unordered_map<int, int> freq;

            for (int x : nums)
                freq[x]++;

            int ans = -1;

            for (auto& [x, f] : freq) {
                if (f == 1)
                    ans = max(ans, x);
            }

            return ans;
        }

        // Only one subarray
        if (k == n) {
            int ans = -1;

            for (int x : nums)
                ans = max(ans, x);

            return ans;
        }

        if (n > 1 && nums[0] == nums[n - 1])
            return -1;

        bool first = true;
        bool last = true;

        for (int i = 1; i < n - 1; i++) {
            if (nums[i] == nums[0])
                first = false;

            if (nums[i] == nums[n - 1])
                last = false;
        }

        int ans = -1;

        if (first)
            ans = max(ans, nums[0]);

        if (last)
            ans = max(ans, nums[n - 1]);

        return ans;
    }
};