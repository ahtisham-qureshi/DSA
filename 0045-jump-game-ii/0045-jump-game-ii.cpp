class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int l = 0;
        int r = 0;

        while(r<n-1){
            int far = r;

            for(int i = l; i<=r;i++){
                far = max(far,nums[i] + i);
            }

            jumps++;
            l = r + 1;
            r = far;
        }

        return jumps;
    }
};