#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, k;
int n, m;
int triangle[2005][2005];

ll sum[2005][2005];
void build() {
	triangle[0][0] = 1;
	for (int i = 1; i <= 2000; ++i) {
		triangle[i][i] = triangle[i][0] = 1;
	}
	for (int i = 2; i <= 2000; ++i) {
		for (int j = 1; j <= i ; ++j)
			triangle[i][j] = (triangle[i - 1][j] + triangle[i - 1][j - 1]) %k;
	}
	for (int i = 2; i <= 2000; ++i) {
		for (int j = 1; j <= i ; ++j) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
			if (triangle[i][j] == 0) {
				sum[i][j] += 1;
			}
			sum[i][j + 1] = sum[i][j];
		}
	}

}

void debug() {
	for (int i = 0; i <= 10; ++i) {
		for (int j = 0; j <= i; ++j) {
			cout << sum[i][j] << " ";
		}
		cout << endl;
	}

}

int main() {
	cin >> t >> k;
	build();
	//debug();
		while 	(t--){
			scanf("%d%d",&n,&m);
			if (m > n)m = n;
			printf("%lld\n",sum[n][m]);

		}
	return 0;
}