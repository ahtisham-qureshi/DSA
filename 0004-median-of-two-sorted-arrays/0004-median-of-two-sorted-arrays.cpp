class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int s = m + n;
        if(n<m) return findMedianSortedArrays(nums2,nums1);

        int str = 0; int end = m;
        int left = (s + 1)/2;

        while(str<=end){
            int mid1 = str + (end-str)/2;
            int mid2 = left - mid1 ;

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if(mid1 < m) r1 = nums1[mid1];
            if(mid2 < n) r2 = nums2[mid2];
            if(mid1 > 0) l1 = nums1[mid1-1];
            if(mid2 > 0) l2 = nums2[mid2-1];

            if(l1<=r2 && l2<=r1){
                if(s%2){
                    return max(l1,l2);
                }else{
                    return double(max(l1,l2) + min(r1,r2))/2.00;
                }
            }else if(l1>r2){
                end = mid1 - 1;
            }else{
                str = mid1 + 1;
            }
        }

        return 0.0;
    }
};
