class Solution {
public:
    int digitSum (int n){
        int sum = 0;
        while(n){
            sum += n%10;
            n = n/10;
        }

        return sum;
    }
    
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0;i<n;i++){
            int sum = digitSum(nums[i]);
            if(sum == i) return i;
        }

        return -1;
    }
};