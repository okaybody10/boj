#include <bits/stdc++.h>
using namespace std;
#define MIN -100000005

struct seg{
    int tot, lef, rig;
    seg() : tot(0), lef(0), rig(0) {}
    seg(int tot, int lef, int rig) : tot(tot), lef(lef), rig(rig) {}
};
seg tree[400006];
int ps[100006];

seg update(int st, int en, int nd, int ch, int val) {
    if(ch < st || en < ch) return tree[nd];
    if(st == en) return tree[nd] = {val, val, val};
    seg left = update(st, (st+en)/2, nd * 2, ch, val);
    seg right = update((st+en)/2+1, en, nd*2+1, ch, val);
    tree[nd].lef = max(left.lef, right.lef + ps[(st+en)/2] - ps[st-1]);
    tree[nd].rig = max(right.rig, left.rig + ps[en] - ps[(st+en)/2]);
    tree[nd].tot = max(left.tot, max(right.tot, left.rig + right.lef));
    return tree[nd];
}

seg ans(int st, int en, int rst, int ren, int nd) {
    if(en < rst || ren < st) return seg(MIN, MIN, MIN);
    if(rst <= st && en <= ren)  return tree[nd];   
    seg left = ans(st, (st+en)/2, rst, ren, nd * 2);
    seg right = ans((st+en)/2+1, en, rst, ren, nd * 2 + 1);
    seg tmp;
    tmp.lef = max(left.lef, right.lef + ps[(st+en)/2] - ps[st-1]);
    tmp.rig = max(right.rig, left.rig + ps[en] - ps[(st+en)/2]);
    tmp.tot = max(left.tot, max(right.tot, left.rig + right.lef));
    return tmp;
}

int main() {
    int n, a[100006];
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        scanf("%d", &a[i]);
        ps[i] = ps[i-1] + a[i];
        update(1, n, 1, i, a[i]);
    }
    // for(int i=1;i<=n;i++) update(1, n, 1, i, a[i]);   
    // for(int i=1;i<=4*n;i++) printf("%d %d %d\n", tree[i].tot, tree[i].lef, tree[i].rig);
    int q;
    scanf("%d", &q);
    while(q--) {
        int st, en;
        scanf("%d %d",&st, &en);
        printf("%d\n", ans(1, n, st, en, 1).tot);
    }
    return 0;
}