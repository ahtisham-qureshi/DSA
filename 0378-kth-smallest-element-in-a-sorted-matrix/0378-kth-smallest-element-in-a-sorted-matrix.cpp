class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<int> pq;

        for(int i = 0;i<n;i++){
            for (int x : matrix[i]) {
                pq.push(x);

                if (pq.size() > k)
                    pq.pop();
            }
        }
        

        return pq.top();
    }
};