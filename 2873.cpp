#include <bits/stdc++.h>
using namespace std;
int mn = 1005, mi, mj;
int mp[1005][1005];

int main() {
    int r, c;
    scanf("%d %d", &r, &c);
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) {
        scanf("%d",&mp[i][j]);
        if((i+j)%2 && mn > mp[i][j]) mn = mp[i][j], mi = i, mj = j;
    }
    if(r%2) {
        for(int i=0;i<r/2;i++) {
            for(int j=1;j<c;j++) printf("R");
            printf("D");
            for(int j=1;j<c;j++) printf("L");
            printf("D");
        }
        for(int j=1;j<c;j++) printf("R");
    }    
    else {
        if(c%2) {
            for(int i=0;i<c/2;i++) {
                for(int j=1;j<r;j++) printf("D");
                printf("R");
                for(int j=1;j<r;j++) printf("U");
                printf("R");
            }
            for(int i=1;i<r;i++) printf("D");
        }
        else {
            for(int i=0;i<r/2;i++) {
                if(i < mi/2) {
                    for(int j=1;j<c;j++) printf("R");
                    printf("D");
                    for(int j=1;j<c;j++) printf("L");
                }
                else if (i==mi/2) {
                    for(int j=0; j<c/2;j++) {
                        if(j< mj/2) {
                            printf("DRU");
                        }
                        else if (j==mj/2) {
                            if(mi%2) printf("RD");
                            else printf("DR");
                        }
                        else {
                            printf("URD");
                        }
                        if(j+1 != c/2) printf("R");
                    }
                }
                else {
                    for(int j=1;j<c;j++) printf("L");
                    printf("D");
                    for(int j=1;j<c;j++) printf("R");
                }
                if(i+1 != r/2) printf("D");
            }
        }
    }
    return 0;
}