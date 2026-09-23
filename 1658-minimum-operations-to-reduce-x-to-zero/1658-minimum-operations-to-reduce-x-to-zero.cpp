class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int total = 0;
        for (int num : nums) {
            total += num;
        }

        int target = total - x;

        if (target == 0)
            return n;

        int left = 0;
        int currSum = 0;
        int maxLen = -1;

        for (int right = 0; right < n; right++) {
            currSum += nums[right];

            while (left <= right && currSum > target) {
                currSum -= nums[left];
                left++;
            }

            if (currSum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        if (maxLen == -1)
            return -1;

        return n - maxLen;
    }
};