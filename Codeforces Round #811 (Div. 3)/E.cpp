#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main(){
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        bool flag = true, end = false; // if % 10 is 0, end = true
        vector<int> v;
        for(int i=0;i<n;i++) {
            int t;
            scanf("%d", &t);
            if(t%10 == 5) end = true, t+=5;
            else if(t%10==0) end = true;
            else{
                while(1) {
                    if(t % 10 == 2) break;
                    t += (t%10);
                }
            }
            v.push_back(t);
        }
        int k = v[0];
        for(int i=1;i<n;i++) {
            int diff = (v[i] > k) ? (v[i]-k) : (k-v[i]);
            if(end) {
                if(diff > 0)
                {
                    flag = false;
                    break;
                }
            }
            else {
                if(diff % 20 > 0) {
                    flag = false;
                    break;
                }
            }
        }
        printf("%s\n", flag ? "Yes" : "No");
    }   
    return 0;
}