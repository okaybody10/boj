#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){
    int q;
    scanf("%d", &q);
    while(q--) {
        bool chk[105]={false};
        string co;
        cin >> co;
        int sz = co.size(), ch = 0;
        vector<pii> ans;
        vector<string> k;
        int t;
        scanf("%d", &t);
        for(int i=0;i<t;i++) {
            string st;
            cin>>st;
            k.push_back(st);
        }
        while(1) {
            if(ch==sz) break;
            int mx = 0, idx = -1, st = -1;
            for(int i=0;i<sz;i++){
                for(int j=0;j<t;j++) {
                    string nw = k[j];
                    int cnt = nw.size(), tmp = 0;
                    bool flag2 = false;
                    for(int l=0;l<cnt;l++) {
                        if(i+l >= sz || nw[l] != co[i+l]) { flag2=true; break; }
                        tmp += (chk[i+l]==false);
                    }
                    if(!flag2 && mx < tmp) mx = tmp, idx = j, st = i;
                }
            }
            if(mx==0) break;
            ans.push_back({idx+1, st+1});
            int ssz = k[idx].size();
            for(int j=0;j<ssz;j++) chk[st + j] = true;
            ch += mx;
        }
        if(ch==sz) {
            printf("%d\n", ans.size());
            for(int i=0;i<ans.size();i++) {
                printf("%d %d\n", ans[i].first, ans[i].second);
            }
        }
        else printf("-1\n");
    }
    return 0;
}