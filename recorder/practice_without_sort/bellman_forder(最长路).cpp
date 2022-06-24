#include <bits/stdc++.h>
using namespace std;
int n, m;
#define MAXN ((int)5e4+10)

struct edge {
	int from, to, len;
	void init(int from, int to, int len) {
		this->from = from, this->to = to, this->len = len;
	}
} v[MAXN];
int dist[1005];


queue<edge>q;
int mark[MAXN];

int main() {
	for (int i = 0; i < 1005; ++i) {
		dist[i] = -0x3f3f3f3f;
	}

	ios::sync_with_stdio(false);
	cin >> n >> m;
//	cout << -0x3f3f3f3f << endl;
//	cout << dist[n] << endl;
	for (int i = 0; i < m; ++i) {
		int len, from, to;
		cin >> from >> to >> len;
//		if (v[i].from==0)
		v[i].init(from, to, len);
//		else {
//			v[i]
//		}
	}

	dist[1] = 0;

	for (int i = 1; i < n; ++i) {

		for (int j = 0; j < m; ++j) {//是更新所有的边，不是j<n...
			int from = v[j].from, to = v[j].to, len = v[j].len;
			dist[to] = max(dist[to], dist[from] + len);

		}
	}

	if (dist[n] == -0x3f3f3f3f)
		cout << -1 << endl;
	else
		cout << dist[n] << endl;

	return 0;
}