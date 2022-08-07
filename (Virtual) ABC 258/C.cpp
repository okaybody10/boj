#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    ll ans = LLONG_MAX - 10;
    //printf("%lld", ans);
    ll last = 0;
    for(int i=1;i<=n;i++) {
        if(x<i) break;
        int a, b;
        scanf("%d %d", &a, &b);
        ll cc = last + a + b;
        ans = min(cc + (ll)b * (ll)(x-i), ans);
        last = cc;
    }
    return !printf("%lld", ans);
}