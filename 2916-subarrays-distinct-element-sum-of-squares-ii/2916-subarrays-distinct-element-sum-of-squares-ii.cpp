
class Solution {
    using ll = long long;
    static const int MOD = 1e9 + 7;

    struct Node {
        ll sum = 0;
        ll sq = 0;
        ll lazy = 0;
    };

    vector<Node> tree;
    int n;

    void apply(int node, int l, int r, ll val) {
        ll len = r - l + 1;
        ll oldSum = tree[node].sum;

        tree[node].sq = (tree[node].sq
            + 2LL * val % MOD * oldSum % MOD
            + len % MOD * val % MOD * val % MOD) % MOD;

        tree[node].sum = (oldSum + len * val) % MOD;
        tree[node].lazy = (tree[node].lazy + val) % MOD;
    }

    void push(int node, int l, int r) {
        if (tree[node].lazy == 0 || l == r) return;

        int mid = l + (r - l) / 2;
        ll val = tree[node].lazy;

        apply(node * 2, l, mid, val);
        apply(node * 2 + 1, mid + 1, r, val);

        tree[node].lazy = 0;
    }

    void update(int node, int l, int r,
                int ql, int qr, ll val) {
        if (ql > r || qr < l) return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }

        push(node, l, r);

        int mid = l + (r - l) / 2;

        update(node * 2, l, mid, ql, qr, val);
        update(node * 2 + 1, mid + 1, r, ql, qr, val);

        tree[node].sum =
            (tree[node * 2].sum + tree[node * 2 + 1].sum) % MOD;

        tree[node].sq =
            (tree[node * 2].sq + tree[node * 2 + 1].sq) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n, Node());

        vector<int> last(100001, -1);
        ll ans = 0;

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            update(1, 0, n - 1, last[x] + 1, i, 1);

            last[x] = i;

            ans = (ans + tree[1].sq) % MOD;
        }

        return ans;
    }
};
