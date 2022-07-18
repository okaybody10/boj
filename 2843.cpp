#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

bool chk[300006];
int tmp[300006], cnt = 1;
int par[300006];
stack<pii> qry;
stack<int> add, ans;

int init(int x, int cnt) {
    tmp[x] = cnt;
    if (tmp[par[x]] == cnt && par[x] != x) chk[par[x]] = true;
    return tmp[par[x]] ? par[x] : (par[x] = init(par[x], cnt));
}

int fin(int x) { return (par[x] == x) ? par[x] : (par[x] = fin(par[x])); }

// x -> y 추가
void merge(int x, int y) {
    x = fin(x);
    y = fin(y);
    if (x == y)
        chk[x] = true;
    else
        par[x] = y;
}

int main() {
    int n, q;
    scanf("%d", &n);
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x);
        par[i] = (x ? x : i);
    }
    scanf("%d", &q);
    while (q--) {
        int op, num;
        scanf("%d %d", &op, &num);
        qry.push({op, num});
        if (op == 2) add.push(par[num]), par[num] = num;
    }
    for (int i = 1; i <= n; i++) if (!tmp[i]) init(i, cnt++);
    while (!qry.empty()) {
        auto p = qry.top();
        qry.pop();
        if (p.first == 1) {
            int t = fin(p.second);
            ans.push((chk[t] ? -1 : t));
        } else {
            int ad = add.top();
            add.pop();
            merge(p.second, ad);
        }
    }
    while (!ans.empty()) ans.top() == -1 ? puts("CIKLUS") : printf("%d\n", ans.top()), ans.pop();
    return 0;
}