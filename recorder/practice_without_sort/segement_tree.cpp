// 可持久化线段树   全持久化系列
//注意内存限制

#include <bits/stdc++.h>
using namespace std;
int n, m;
const int MAXN = 2e7 + 5000000;
//top 为内存池,root 保存根节点,a保存临时数据
int a[1000005], root[MAXN], top;

struct node {
    int l, r, v;
} Tree[MAXN];

int build (int pos, int left, int right) {
    pos = ++top;
    if (left == right) {
        Tree[pos].v	 = a[left];
        return top;
    }
    int mid = left + right >> 1;
    Tree[pos].l=build(Tree[pos].l, left, mid);
    Tree[pos].r=build(Tree[pos].r, mid + 1, right);
    return pos;
}

int clone(int pos) {
    Tree[++top]=Tree[pos];
    return top;
}

int update(int pos, int begin, int end, int idx, int val) {
    pos = clone(pos);
    if (begin == end) {
        Tree[pos].v = val;
//        return pos;
    } else {
        int mid = (begin + end) >> 1;
        if (idx <= mid)
            Tree[pos].l=update(Tree[pos].l, begin, mid, idx, val);
        else
        Tree[pos].r=update(Tree[pos].r, mid + 1, end, idx, val);
    }return pos;

}

//不写 return 会默认返回0...尤其是递归调用，所有出口的return都得写
int query(int pos, int left, int right, int idx) {
    if (left==right){
        return Tree[pos].v;
    }
    int mid = left + right >> 1;
    if (idx <= mid) {
      return   query(Tree[pos].l, left, mid, idx)
                ;
    } else {
        return query(Tree[pos].r, mid+1, right, idx);
    }

}

//void DEBUG() {
//    for (int i = 0; i < n; ++i) {
//
//    }
//}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    root[0]=build(0,1,n);
    root [0] = 1;
    for (int i = 1; i <= m; ++i) {
        int v, opt, idx;
        scanf("%d%d%d", &v, &opt, &idx);
        if (opt == 1) {
            int val;
            scanf("%d", &val);
            root[i] = update(root[v], 1, n, idx, val);
        } else {
            printf ("%d\n", query(root[v], 1, n, idx));
//        cout<<query(root[v],1,n,idx)<<endl;
        root[i] = root[v];
        }

    }

    return 0;
}

