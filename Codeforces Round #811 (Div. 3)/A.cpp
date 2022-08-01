#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int t, h, m, mn = 36886;
        scanf("%d %d %d", &t, &h, &m);
        int nw = 60 * h + m;
        for(int i=0;i<t;i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            int calc = 60 * a + b;
            int v = (calc - nw + 1440) % 1440;
            mn = min(v, mn);
        }
        printf("%d %d\n", mn / 60, mn % 60);
    }
    return 0;
}