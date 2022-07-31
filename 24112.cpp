#include <bits/stdc++.h>
using namespace std;
#define MOD 1234567

int dp[500005], ps[500005], a[500005], dpk[500005];

int main() {
    int n, p;
    scanf("%d %d",&n,&p);
    for(int i=1;i<=n;i++) {
        scanf("%d", &a[i]);
        ps[i]=ps[i-1]+a[i]; // i번째까지의 누적합
    }
    dp[n]=dpk[n]=1;
    for(int i=n-1;i>=0;i--) {
        int t = ps[i];
        int idx = upper_bound(ps + i, ps + n + 1, t + p) - ps;
        // if(idx > n) idx = n;
        //printf("%d %d %d %d ", i, idx, t+p, ps[idx]);
        dp[i] = (dpk[i+1] - dpk[idx] + MOD) % MOD;
        dpk[i] = (dpk[i+1] + dp[i]) % MOD;
        //printf("%d %d\n", dp[i], dpk[i]);
    }
    return !printf("%d\n", dp[0]);
}