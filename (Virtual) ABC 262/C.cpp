#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int n, ar[500006], same = 0;
    scanf("%d", &n);
    ll ans = 0;
    for(int i=1;i<=n;i++) scanf("%d", &ar[i]), same += (ar[i] == i);
    for(int i=1;i<=n;i++) {
        int t = ar[i];
        if(t < i) continue;
        if(t==i) ans += (--same);
        else ans += (i == ar[t]);
    }
    return !printf("%lld", ans);
}