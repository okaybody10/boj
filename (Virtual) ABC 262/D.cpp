#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define MOD 998244353

int main() {
    int n, a[105];
    int ans = 0;
    scanf("%d", &n);
    for(int i=1;i<=n;i++) scanf("%d", &a[i]);
    for(int i=1;i<=n;i++) {
        int dp[105][105][105]={0};
        for(int i=0;i<=n;i++) dp[i][0][0]= 1;
        // i-th average
        // dp[a][b][c]: 1~a index, choose b's, remainder: c
        for(int j=1;j<=n;j++) {
            for(int k=1;k<=i;k++){
                for(int l=0;l<i;l++) {
                    dp[j][k][l] += dp[j-1][k][l];
                    dp[j][k][(l+a[j])%i] += dp[j-1][k-1][l];
                    dp[j][k][l] %= MOD;
                    dp[j][k][(l+a[j])%i] %= MOD;
                }
            }
        }
        ans += dp[n][i][0];
        ans %= MOD;
    } 
    return !printf("%d", ans);
}