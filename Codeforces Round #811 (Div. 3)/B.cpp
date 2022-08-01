#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){
    int q;
    scanf("%d", &q);
    while(q--) {
        bool chk[200006]={0};
        queue<int> qu;
        int n;
        scanf("%d", &n);
        int ans = 0;
        for(int i =0; i<n;i++) {
            int t;
            scanf("%d", &t);
            if(chk[t]) {
                while(qu.front() != t){
                    chk[qu.front()] = false;
                    qu.pop();
                    ans++;
                }
                qu.pop();
                ans++;
            }
            chk[t] = true;
            qu.push(t);
        }
        printf("%d\n", ans);
    }
    return 0;
}