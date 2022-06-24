/*
八国王问题  dp压缩
luogu
*/
#include <bits/stdc++.h>
using namespace std;
int n, k;
typedef long long ll;
ll dp[10][1 << 10][85];
ll state[77777], king[777777];
ll ans, sum = 0;

//初始化一行的状态，国王数目和方案数
void init () {
	int tot = (1 << n) - 1;
	for (int i = 0; i <= tot; ++i) {
		//state记录一行所有可能方案状况
		if (!((i << 1)&i)) {
			state[++ans] = i;
			int t = i;
			while (t) {
				king[ans] += t % 2;
				t >> 1;
			}
		}
	}
//    cout<<ans<<endl;
}

int main() {
	cin >> n >> k;
	init();
	for (int i = 1; i <= ans; ++i) {
		if (king[i] <= k)
			dp[1][i][king[i]] = 1; //初始化第一行

	}

	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j <= ans; ++j) {
			for (int p = 1; p <= ans; ++p) {
				if (state[j]&state[p])
					continue;
				if (state[j] & (state[p] << 1))
					continue;
				if ((state[j] << 1)&state[p])
					continue;

				//枚举国王数
				for (int s = 1; s <= k; ++s) {
					if (king[j] + s > k)
						continue;
					dp[i][j][king[j] + s] += dp[i - 1][p][s]; //右边是上一行的国王数
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= ans; ++j) {
			sum += dp[i][j][k];
		}
	}

	cout << sum << endl;

	return 0;
}