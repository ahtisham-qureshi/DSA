class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int zero = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zero = i;
                break;
            }
        }

        bool inc = true, dec = true;

        for (int i = 1; i < n; i++) {
            int prev = nums[(zero + i - 1) % n];
            int curr = nums[(zero + i) % n];

            if (curr != (prev + 1) % n) {
                inc = false;
            }

            if (prev != (curr + 1) % n) {
                dec = false;
            }
        }

        if (inc) {
            return min(zero, n - zero + 2);
        }

        if (dec) {
            return min(zero + 2, n - zero);
        }

        return -1;
    }
};