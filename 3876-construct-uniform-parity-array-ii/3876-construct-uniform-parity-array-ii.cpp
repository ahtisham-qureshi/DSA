class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini = nums1[0];
        bool isOdd = false;

        for (int x : nums1) {
            mini = min(mini, x);

            if (x % 2)
                isOdd = true;
        }

        return mini % 2 || !isOdd;
    }
};