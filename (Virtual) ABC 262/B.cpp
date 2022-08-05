#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> v[105];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=0;i<m;i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b), v[b].push_back(a);
    }
    int ans = 0;
    for(int i=1;i<=n;i++) {
        int t= v[i].size();
        for(int j=0;j<t;j++) {
            if(i>=v[i][j]) continue;
            int se =v[i][j];
            int k = v[se].size();
            for(int l=0;l<k;l++) {
                if(se >= v[se][l]) continue;
                int th = v[se][l];
                int kk = v[th].size();
                for(int q=0;q<kk;q++) {
                    ans += (v[th][q]==i);
                }
            }
        }
    }
    return !printf("%d", ans);
}