#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,a[100005],b[100005];
bool check(ll t){
    ll need=0,rest=0;
    for(int i=n-1;i>=0;i--){
        if(rest>=b[i]){
            rest-=b[i];
        }else{
            ll task=b[i]-rest;
            ll work=t-a[i];
            ll num=(task+work-1)/work;
            need+=num;
            rest=work*num-task;
        }
    }
    return need<=k;
}
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    ll s=0;
    for(int i=0;i<n;i++){
        cin>>b[i];
        s+=b[i];
    }
    ll lo=a[n-1], hi=a[n-1]+s;
    while(hi-lo>1){
        ll m=(lo+hi)/2;
        if(check(m))hi=m;
        else lo=m;
    }
    cout<<hi<<endl;
}