class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> pq;
        for(int i : nums) pq.push(i);

        int j = k;
        while(j>1){
            pq.pop();
            j--;
        }

        return pq.top();
    }
};
