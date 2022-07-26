#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
#define MAX 2000000000005
#define x first
#define y second

int p;
ll l, r, v;
vector<pli> co;
ll a[200006], ans[200006];

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    a[0] = -MAX, a[n+1] = MAX;
    for(int i = 1; i<=n;i++) scanf("%lld", &a[i]), co.push_back({a[i+1]-a[i], i}); // range
    sort(co.begin(), co.end());
    while(q--) {
        ll t;
        scanf("%lld", &t);
        if(t>=0) {
            // if t > 0, wind is east direction
            // That means, snowball goes to right, so update right value
            // If |now wind value| > |before wind value|, update. else, not update => max operation
            v += t;
            r = max(r, v);
            // if l + r > (range) + wind east, so Left snowball will be moved
            // Right snowball's weight: L, Left snowball's weight: (range)-L
            // After that, doesn't remain weight => skip
            while(p<=n && co[p].x <= l+r) {
                ans[co[p].y+1] += l;
                ans[co[p].y] += co[p].x - l;
                ++p;
            }
        }
        else {
            // if t < 0, wind is west direction
            // That means, snowball goes to left, so update left value
            // If |now wind value| > |before wind value|, update. else, not update => max operation
            v += t;
            l = max(l, -v);
            while(p<=n && co[p].x <= l+r) {
                ans[co[p].y] += r;
                ans[co[p].y+1] += co[p].x - r;
                ++p;
            }
        }
    }
    for(int i=1;i<=n;i++) printf("%d\n", co[p].y);
    while(p<=n) {
        ans[co[p].y] += r;
        ans[co[p].y + 1] += l;
        ++p;
    }
    for(int i=1; i<=n;i++) printf("%lld\n", ans[i]);
    return 0;
}