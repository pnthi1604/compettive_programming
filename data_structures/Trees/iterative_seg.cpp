struct SegmentTree {
    int n;
    vector<int> tree;
    SegmentTree() {}
    SegmentTree(int _n): n(_n), tree(n * 2, -INF) {}
    void clear() {
        fill(tree.begin(), tree.end(), -INF);
    }
    void update(int i, int val) {
        tree[i += n] = val;
        for (i /= 2; i > 0; i /= 2) {
            tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
        }   
    }
    int query(int l, int r) {
        int res = -INF;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l & 1) res = max(res, tree[l++]);
            if (r & 1) res = max(res, tree[--r]);
        }
        return res;
    }
};
