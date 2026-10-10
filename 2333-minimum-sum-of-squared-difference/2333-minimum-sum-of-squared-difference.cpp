class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        int n = nums1.size();
        
        vector<long long> diff(n);
        long long total_diff = 0;
        for (int i = 0; i < n; ++i) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total_diff += diff[i];
        }
        
        if (total_diff <= k) return 0;
        
        sort(diff.begin(), diff.end());
        
        long long low = 0, high = diff.back(), target_max = high;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long ops_needed = 0;
            for (int i = 0; i < n; ++i) {
                if (diff[i] > mid) {
                    ops_needed += (diff[i] - mid);
                }
            }
            if (ops_needed <= k) {
                target_max = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (diff[i] > target_max) {
                k -= (diff[i] - target_max);
                diff[i] = target_max;
            }
        }
        
        for (int i = n - 1; i >= 0 && k > 0; --i) {
            if (diff[i] == target_max && diff[i] > 0) {
                diff[i]--;
                k--;
            }
        }
        
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += diff[i] * diff[i];
        }
        
        return ans;
    }
};