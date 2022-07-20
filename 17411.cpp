#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define x first
#define y second

pii seg[4000007];
// seg_tree, which type of node is pair: {length, count}
// 1. If left(or right)'s length is larger than others, left(or right)'s node = self node
// 2. If length of left node and right node are same, self node's value = {length, count_left + count_right}
// When we update value at position i, perform following logic
// First, Coordinate compression of a[i] is t, find the maximum length of 1 ~ t-1
// Second, update value above logic
// TODO: Coordinate compression of input values => initation

pii add_pii(pii a, pii b) {
    if(a.x > b.x) return a;
    else if(a.x < b.x) return b;
    return {a.x, a.y + b.y};
}

pii update(int st, int en, int nd, int ch, pii val) {
    if(ch < st || en < ch) return seg[nd];
    if(st == en) return seg[nd] = add_pii(seg[nd], val);
    pii left = update(st, (st+en)/2, nd*2, ch, val);
    pii right = update((st+en)/2+1, en, nd*2+1, ch, val);
    return seg[nd] = add_pii(left, right);
}

pii ans(int st, int en, int rst, int ren, int nd) {
    if(rst > ren) return {0, 0};
    if(ren < st || en < rst) return {0, 0};
    if(rst <= st && en <= ren) return seg[nd];
    pii left = ans(st, (st + en)/2, rst, ren, nd*2);
    pii right = ans((st+en)/2+1, en, rst, ren, nd*2+1);
    return add_pii(left, right);
}

int main() {
    int n, c[1000007];
    vector<int> a, sa;
    scanf("%d", &n);
    for(int i=0, x;i<n;i++) scanf("%d", &x), a.push_back(x);
    sa = a;
    sort(sa.begin(), sa.end());
    sa.erase(unique(sa.begin(), sa.end()), sa.end());
    for(int i=0;i<n;i++) c[i] = lower_bound(sa.begin(), sa.end(), a[i]) - sa.begin() + 1;
    int sz = sa.size();
    // seg tree update
    for(int i=0;i<n;i++) {
        pii f = ans(1, sz, 1, c[i]-1, 1);
        update(1, sz, 1, c[i], {f.x + 1, max(f.y, 1)});
    }
    printf("%d %d\n", seg[1].x, seg[1].y);
    return 0;
}