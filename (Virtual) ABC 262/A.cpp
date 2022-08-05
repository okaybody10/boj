#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int n;
    scanf("%d", &n);
    for(;;n++) {
        if(n%4==2) break;
    }
    return !printf("%d", n);
}