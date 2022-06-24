//splay 通过每次查询将查询点旋转到顶部来保持平衡
//一种平衡二叉树
//增删查改
//前驱和后驱的求解问题


#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
struct Node
{
    int ch[2], size, cnt, val, fa;
    void init(int _val, int _fa)
    {
        val = _val, fa = _fa;
        cnt = 1, size = 1;
    }
} t[N];

int root = 0, cnt = 0, n;

#define push_up(x) t[x].size = t[t[x].ch[0]].size + t[t[x].ch[1]].size + t[x].cnt;




int get(int x)//判断是 左还是右节点
{
    return t[t[x].fa].ch[1] == x;
}

void rotate(int x)//旋转范式
{
    int fa = t[x].fa, gfa = t[fa].fa;
    int ws = get(x), wsf = get(fa);
    t[fa].ch[ws] = t[x].ch[ws ^ 1], t[t[x].ch[ws ^ 1]].fa = fa;
    t[gfa].ch[wsf] = x, t[x].fa = gfa;
    t[fa].fa = x, t[x].ch[ws ^ 1] = fa;
    push_up(fa);
    push_up(x);
}

void splay(int x, int goal) {//旋转哪个点
    while (t[x].fa != goal) {
        int fa = t[x].fa, gfa = t[fa].fa;
        int d1 = get(x), d2 = get(fa);
        if (gfa != goal) {
            if (d1 == d2) rotate(fa);
            else rotate(x);
        }
        rotate(x);
    }
    if (goal == 0) root = x;
}


void insert(int val)//点插入
{
    int node = root, fa = 0;
    while (node && t[node].val != val)
    {
        fa = node, node = t[node].ch[t[node].val < val];
    }
    if (node)
        t[node].cnt++;
    else
    {
        node = ++cnt;
        if (fa)
            t[fa].ch[t[fa].val < val] = node;
        t[node].init(val, fa);
    }
    splay(node, 0);
}

int find(int val)
{
    int node = root;
    int next_node = t[node].ch[val < t[node].val ? 0 : 1];
    //  迭代的下一个节点  t[node].ch [ val<t[node].val ? 0 :1          ]
    while (t[node].val != val && next_node)
    { //当前节点是否为所需节点  且 迭代的下一个节点是否存在
        //node = t[node].ch[t[node].ch[t[node].val < val]];
        node = next_node;
        next_node = t[node].ch[val < t[node].val ? 0 : 1];
    }
    return node;
}


int near(int val, int kind) // kind=0 找前驱，kind=1找后驱
{
    splay(find(val), 0); // find接口设计 是找最接近的 不一定相等
    int node = root;
    if (t[node].val < val && kind == 0)
        return node;
    if (t[node].val > val && kind == 1)
        return node;
    node = t[node].ch[kind];
    while (t[node].ch[kind ^ 1])//异向节点前进
        node = t[node].ch[kind ^ 1];
    return node;
}



void delet(int val)
{
    int last = near(val, 0), next = near(val, 1);
    splay(last, 0);
    splay(next, last);
    int& now = t[next].ch[0];//引用后才能 真正意义上删除
    if (t[now].cnt > 1)
    {
        t[now].cnt -= 1;
        splay(now, 0);
    }
    else
    {
        now = 0; //将 父亲的儿子设为零  就无法访问  无法改变cnt       无法访问==删除一个点
    }
}

int k_th(int k)
{
    int node = root;
    if (t[node].size < k)
        return INF;
    while (1)
    {
        int son = t[node].ch[0];
        if (k <= t[son].size)
            node = son;
        else if (k > t[son].size + t[node].cnt)
        { //将重复节点也要考虑   与普通删除不一样
            k -= t[son].size + t[node].cnt;
            node = t[node].ch[1];
        }
        else return t[node].val;
    }
}


int get_rank(int val)
{
    splay(find(val), 0);
    return t[t[root].ch[0]].size;//妥协了本身的点 插入了哨兵
}

int main()
{
    //freopen("try.txt", "w", stdout);
    insert(INF), insert(-INF);
    cin >> n;
    while (n--) {
        int opt, num;
        scanf("%d%d", &opt, &num);
        switch (opt)
        {
        case 1/* constant-expression */:
            /* code */
            insert(num);
            break;
        case 2:
            delet(num);
            // default:

            break;
        case 3:
            printf("%d\n", get_rank(num));
            break;
        case 4:
            printf("%d\n", k_th(num + 1));
            break;
        case 5:
            printf("%d\n", t[near(num, 0)].val);
            break;
        case 6:
            printf("%d\n", t[near(num, 1)].val);
            break;
        }
    }

    return 0;
}