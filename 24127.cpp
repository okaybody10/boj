#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<ll> chk;
int main() {
    int n,k;
    scanf("%d", &n);
    int a[1000006];
    for(int i=0;i<n;i++) {
        scanf("%d", &a[i]);
        a[i] %= 2;
    }
    for(int i=n;i<n*n*n*n;i++) {
        a[i] = (a[i-1] + a[i-n]) % 2;
    }
    for(int i=0;i<n*n*n;i++) {
        ll t = 0;
        for(int j=0;j<n;j++) t <<= 1, t += a[i * n+ j];// printf("%d", a[i*n+j]);
        //printf(",\t");
        if(chk.count(t) > 0) return !printf("result: %d\n", i);
        chk.insert(t);
        // printf("now: %d\n", t);
    }
    return 0;
}