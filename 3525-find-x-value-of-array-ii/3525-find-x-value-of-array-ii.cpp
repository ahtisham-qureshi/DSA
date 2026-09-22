class Solution {
public:
    struct Node {
        int prod = 1;
        int cnt[5] = {0, 0, 0, 0, 0};
    };

    int k;
    vector<Node> tree;

    Node merge(Node left, Node right) {

        Node res;

        // Product of entire segment
        res.prod = (left.prod * right.prod) % k;

        // Prefixes completely inside left
        for (int r = 0; r < k; r++) {
            res.cnt[r] += left.cnt[r];
        }

        // Prefixes which enter right
        for (int r = 0; r < k; r++) {
            int newR = (left.prod * r) % k;
            res.cnt[newR] += right.cnt[r];
        }

        return res;
    }

    void build(vector<int>& nums, int node, int l, int r) {

        if (l == r) {

            int val = nums[l] % k;

            tree[node].prod = val;
            tree[node].cnt[val] = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(nums, node * 2, l, mid);
        build(nums, node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, int value) {

        if (l == r) {

            value %= k;

            tree[node] = Node();

            tree[node].prod = value;
            tree[node].cnt[value] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid) {
            update(node * 2, l, mid, idx, value);
        } else {
            update(node * 2 + 1, mid + 1, r, idx, value);
        }

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {

        if (ql <= l && r <= qr) {
            return tree[node];
        }

        int mid = (l + r) / 2;

        // Completely in left
        if (qr <= mid) {
            return query(node * 2, l, mid, ql, qr);
        }

        // Completely in right
        if (ql > mid) {
            return query(node * 2 + 1, mid + 1, r, ql, qr);
        }

        // Both sides
        Node left = query(node * 2, l, mid, ql, qr);

        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    vector<int> resultArray(vector<int>& nums, int K,
                            vector<vector<int>>& queries) {

        k = K;

        int n = nums.size();

        tree.resize(4 * n);

        build(nums, 1, 0, n - 1);

        vector<int> ans;

        for (auto& q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Persistent update
            update(1, 0, n - 1, index, value);

            // Query suffix [start ... n-1]
            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};