#include<bits/stdc++.h>
using namespace std;
int n,p;
typedef long long ll;
#define MAXN ((int)3e6+10)
ll inv[MAXN];
int main(){
    cin>>n>>p;
    inv[1]=1;
    for (int i=2;i<=n;++i){
        inv[i]=(p-p/i)*inv[p%i]%p;
    }
    for (int i=1;i<=n;++i){
        cout<<inv[i]<<"\n";
    }
    return 0;
}