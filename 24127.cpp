#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int sz = 2;
int ar[27];
vector<ll> sm;
ll p, q, nw;
ll ans;

void init(int m) {
    while(1) {
        ll calc=0;
        int od=0;
        for(int i=0;i<m;i++) {
            ar[i] = ((i==0 ? ar[m-1] : ar[i-1]) ^ ar[i]);
            if(ar[i] == 1) od++;
            calc<<=1, calc+=ar[i];
        }
        //for(int i=0;i<m;i++) printf("%d", ar[i]);
        if(nw == calc) break;
        sm.push_back(sm[sz-1]+od);
        //sm[sz] = sm[sz-1] + od;
        sz++;
    }
    --sz;
}

int main() {
    sm.push_back(0);
    int m;
    scanf("%d %lld %lld", &m, &p, &q);
    --p, --q;
    int od = 0;
    for(int i=0;i<m;i++) {
        scanf("%d", &ar[i]);
        ar[i] %= 2;
        od += ar[i];
        nw <<= 1, nw += ar[i];
    }
    sm.push_back(sm[0]+od);
    init(m);
    ll x = sz * m, it = sm[sz];
    ll range = (q-p+1);
    ans += (ll)(range / x) * it;
    p %= x, q %= x;
    if(p<q) {
        for(int i = 0; i < x; i++) {
            int t= i%m;
            if(i>=m) ar[t] = ((t==0 ? ar[m-1] : ar[t-1]) ^ ar[t]);
            if(i>=p && i<=q) ans += (ll)ar[t];
        }
    }
    else {
        for(int i = 0; i < x; i++) {
            int t= i%m;
            if(i>=m) ar[t] = ((t==0 ? ar[m-1] : ar[t-1]) ^ ar[t]);
            if(i<=q || i>=p) ans += ar[t];
        }
    }
    return !printf("%lld", ans);
}