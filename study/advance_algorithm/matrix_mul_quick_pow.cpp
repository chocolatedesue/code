#include<bits/stdc++.h>
using namespace std;
#define MOD ((int)1e9+7)
typedef long long ll;
//¾ØÕó³Ë·¨¼Ó¿ìËÙÃÝ
ll n, k;//Âå¹È¶¾Áö longlong


class matrix {
public:
    ll m[105][105]={0};
    int col, row;
    void init(int col, int row) {
        this->col = col, this->row = row;
    }
    void stand() {
        for (int i = 0; i < col; ++i) {
            m[i][i] = 1;
        }
    }

   void operator =(matrix a) {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                m[i][j] = a.m[i][j];
            }
        }
    }
    matrix operator*(matrix a) {
        matrix ans;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    ans.m[i][j] = ((m[i][k] * a.m[k][j])%MOD + ans.m[i][j]) % MOD;
                }
            }
        }
        ans.col = ans.row = n;
        return ans;
    }
};

matrix qpow(matrix a, ll k) {
    matrix res;
    res.col = res.row = n;
    res.stand();
    while (k)
    {
        if (k & 1) res = (a * res);
            
       
        a = (a * a);
        k = k >> 1;
    }
    return res;
}

matrix temp;

int main() {
    cin >> n >> k;
    temp.col = temp.row = n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%lld", &temp.m[i][j]);
        }
    }
    temp = qpow(temp, k);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << temp.m[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}