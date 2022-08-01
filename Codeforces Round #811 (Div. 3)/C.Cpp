#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){
    int q;
    scanf("%d", &q);
    while(q--) {
        vector<int> v;
        int n, ans = 0;
        scanf("%d", &n);
        int cp = n;
        for(int i=9;i>=1;i--) {
            if(cp <= i) break;
            cp -= i;
            v.push_back(i);
        }
        v.push_back(cp);
        reverse(v.begin(), v.end());
        int sz = v.size();
        for(int i = 0 ;i<sz;i++) ans *= 10, ans += v[i];
        printf("%d\n", ans);
    }
    return 0;
}