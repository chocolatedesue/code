#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
typedef long long ll;
//线段树1 https://www.luogu.com.cn/problem/P3372
// 区分  保存区间，查询区间，节点位置
// 优化 拆开结构体...不然就是Tree[Tree[cur].left].val;

struct node {
    ll val, l, r, tag;
} Tree[MAXN * 8];
int n, m;
int a[MAXN];
inline void push_up(int cur) {
    Tree[cur].val = Tree[Tree[cur].l].val + Tree[Tree[cur].r].val;
}

void build(int left, int right, int cur) {
    if (left == right) {
        Tree[cur].val = a[left];
        return ;
    }
    int mid = left + right >> 1;
    Tree[cur].l = cur << 1, Tree[cur].r = cur << 1 | 1;


        build(left, mid, Tree[cur].l);
        build(mid + 1, right, Tree[cur].r);

        push_up(cur);

}

inline void push_down(int cur, int left, int right) {
    ll num = Tree[cur].tag, mid = left + right >> 1;
    Tree[cur].tag = 0;
    Tree[Tree[cur].l].tag += num, Tree[Tree[cur].l].val += (mid + 1 - left) * num;
    Tree[Tree[cur].r].tag += num, Tree[Tree[cur].r].val += (right - mid) * num;
}

void update(int cur, int l, int r, int val, int pl, int pr) { //l,r为当前节点区间，pl,rl为更新区间
    if (l >= pl && r <= pr) {
        Tree[cur].val += val*(r-l+1);
        Tree[cur].tag += val;
        return ;
    } else {
        //查询与搜索等效  也要push_down
        push_down(cur,l,r);
        int mid = r+l>>1;
        if (pl<=mid) update (Tree[cur].l, l, mid, val, pl, pr);
        if (pr>mid) update (Tree[cur].r, mid + 1, r, val, pl, pr);
        push_up(cur);

//        if (r<pl || l>pr){
//            return ;
//        }
//       else {
//            int mid = l + r >> 1;
//            update (Tree[cur].l, l, mid, val, pl, pr);
//            update (Tree[cur].r, mid + 1, r, val, pl, pr);
//            push_up(cur);
//        }
    }
}



ll query (int cur, int l, int r, int pl, int pr) {
    if (l >= pl && r <= pr) {
        return Tree[cur].val;
    }
    ll res = 0;
    push_down(cur, l, r);
    int mid = l + r >> 1;
    if (pl<=mid)res+=query(Tree[cur].l, l, mid, pl, pr);
    if (pr>mid)res+=query(Tree[cur].r, mid + 1, r, pl, pr);
    return res ;
//    if (l<=pr && r>=pl) {
//

//            ll left = query(Tree[cur].l, l, mid, pl, pr);
//            ll right = query(Tree[cur].r, mid + 1, r, pl, pr);
//            return left + right;
//
//    } else
//        return 0;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
    }
    build (1,n,1);

    for (int i = 1; i <= m; ++i) {
        int opt;
        cin >> opt;
        if (opt == 1) {
            int l, r, val;
            cin >> l >> r >> val;
            update(1, 1, n,val, l, r);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << "\n";
        }

    }

    return 0;
}