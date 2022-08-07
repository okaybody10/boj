#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int cnt = 0, n;
    ll ans = 0;
    int a[15][15];
    scanf("%d", &n);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d", &a[i][j]);
    int mx = -1, mxi, mxj;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(mx < a[i][j]) mx = a[i][j];
}