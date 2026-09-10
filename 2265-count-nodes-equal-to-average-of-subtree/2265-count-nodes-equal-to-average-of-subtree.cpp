class Solution {
public:
    int ans = 0;

    pair<long long, int> solve(TreeNode* root) {
        if (!root) return {0, 0};

        auto [ls, ln] = solve(root->left);
        auto [rs, rn] = solve(root->right);

        long long sum = ls + rs + root->val;
        int n = ln + rn + 1;

        if (sum / n == root->val)
            ans++;

        return {sum, n};
    }

    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};