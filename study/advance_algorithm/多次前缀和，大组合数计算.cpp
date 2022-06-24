#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MOD ((int)1e9+7)
#define MAXN 2008
int n, k;
int a[MAXN];
ll c[MAXN];
ll inv[MAXN];
ll ans[MAXN];

void init() {
    inv[1]=inv[0]=1;
    for (int i=2;i<MAXN;++i){
        inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
    }
    c[0]=1;
    for (int i=1;i<MAXN;++i){
        c[i]=(c[i-1]*inv[i]%MOD*(i+k-1))%MOD;
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    init();
    if (!k) {
        for (int i = 1; i <= n; ++i)
            cout << a[i] << " ";
    } else {

        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                //k<=1e9稳定爆组合数
//                ans[j] = (ans[j] + C(k + j - i - 1, min(k - 1, j - i)) * (ll) a[i]) % MOD;
                ans[j]=(ans[j]+c[j-i]*(ll)a[i]%MOD)%MOD;
            }
        }
        for (int i = 1; i <= n; ++i) {
            cout << ans[i] << " ";
        }

    }
    cout << endl;
    return 0;
}