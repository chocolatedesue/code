#include<bits/stdc++.h>
using namespace std;
int n, m;

int total = 0, root = 0;
#define MAXN ((int)1e5+5)


struct node {
	int ch[2], fa, val, mark, size;
	void init(int _val, int _fa) {
		fa = _fa, val = _val;
		size = 1;
	}
};

node tree[MAXN];

void pushdown(int x) {
	if (tree[x].mark) {

		int l_ch = tree[x].ch[0], r_ch = tree[x].ch[1];
		tree[l_ch].mark ^= 1, tree[r_ch].mark ^= 1;
		tree[x].mark = 0;
		swap(tree[x].ch[1], tree[x].ch[0]);
	}
}


void pushup(int x) {
	tree[x].size = tree[tree[x].ch[0]].size + tree[tree[x].ch[1]].size + 1;
}
//void rotate(int x) {
//	int fa = tree[x].fa, gfa = tree[fa].fa;
//	int ws = tree[fa].ch[1] == x, wsf =  tree[gfa].ch[1] == fa;
//	int side_ch = tree[x].ch[!ws];
//	tree[gfa].ch[wsf] = x, tree[x].fa = gfa, tree[x].ch[!ws] = fa, tree[fa].ch[ws] = side_ch;
//	tree[side_ch].fa = fa, tree[fa].fa = x;
//	pushup(fa), pushup(x);
//}

void rotate(int x) // ����������ͳһ��һ������
{
	int parent = tree[x].fa, grandparent = tree[parent].fa;
	int k = tree[parent].ch[1] == x; // k = 0 ��ʾx��parent������ӣ�k = 1��ʾx��parent���Ҷ���
	
	tree[grandparent].ch[tree[grandparent].ch[1] == parent] = x;
	tree[x].fa = grandparent;

	tree[parent].ch[k] = tree[x].ch[k ^ 1];
	tree[tree[x].ch[k ^ 1]].fa = parent;

	tree[x].ch[k ^ 1] = parent;
	tree[parent].fa = x;

	pushup(parent);
	pushup(x);
}

void splay(int x, int k)
{
	while (tree[x].fa != k) { // ѭ��ֱ�������Ϊk��k=0��ʾ��x���˸�����Ϊ��ʱ�����Ϊ0
		int parent = tree[x].fa, grandparent = tree[parent].fa;
		if (grandparent != k) { // ���游��㣬Ҫת����
			if ((tree[parent].ch[1] == x) ^ (tree[grandparent].ch[1] == parent)) rotate(x); // LR�ͻ���RL��
			else rotate(parent); // LL�ͻ���RR��
		}
		rotate(x);
	}
	if (!k) root = x;
}



//void splay(int val, int goal) {
//	//	int x = find(val);
//	int x = val;
//	while (tree[x].fa != goal) {
//		int fa = tree[x].fa, gfa = tree[fa].fa;
//		int ws = tree[fa].ch[1] == x, wsf = tree[gfa].ch[1] == fa;
//		if (gfa != goal) {
//			if (ws == wsf) {
//				rotate(fa);
//			}
//			else rotate(x);
//		}rotate(x);
//	}
//	if (goal == 0)root = x;
//
//}



//void find (int )


int k_th(int k) 
{
    int u = root;
    while (true) {
        pushdown(u); // ��Ҫpushdown(u)
        if (tree[tree[u].ch[0]].size >= k) // ��������������
            u = tree[u].ch[0];
        else if ((tree[tree[u].ch[0]].size + 1) == k) // �����
            return u;
        else k -= (tree[tree[u].ch[0]].size + 1), u = tree[u].ch[1];
    }
    return -1;
}
 
 



void insert(int x) {
	int u = root, ff = 0;
	while (u) ff = u, u = tree[u].ch[x > tree[u].val];// ��������ֵ�Ƚ�  ����size�Ƚ�  ���ǹ�ϵ�ͱȽ�  ���ֳ�������
	u = ++total;
	if (ff)tree[ff].ch[x > tree[ff].val] = u;
	//	else root = u;
	tree[u].init(x, ff);
	splay(u, 0);
}




void output(int u) {
	
	pushdown(u);
	if (tree[u].ch[0])	output(tree[u].ch[0]);
	if (tree[u].val >= 1 && tree[u].val <= n)printf("%d ", tree[u].val);
	if (tree[u].ch[1]) output(tree[u].ch[1]);

}


int main() {


	cin >> n >> m;
	for (int i = 0; i <= n + 1; ++i)insert(i);
	while (m--) {
		int l, r;
		scanf("%d%d", &l, &r);
		l = k_th(l), r = k_th(r + 2);
		splay(l, 0), splay(r, l);
		//	swap(tree[l].val,tree[r].val);
		tree[tree[r].ch[0]].mark ^= 1;
	}
	output(root);


}


//A