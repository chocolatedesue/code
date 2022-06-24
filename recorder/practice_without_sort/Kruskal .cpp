/*
    1. 将边权排序
    2. 从头开始循环取边
    3. 用并查集判断是否连接  没有连接则添加，有就跳过
    4. 直至没有边或已经加入n-1条边结束
*/
#include<bits/stdc++.h>
using namespace std;
int n, m;
#define MAX_N 5005
int f[MAX_N], sizes[MAX_N];
struct node{
    int start, to, cost;
    bool operator<(const node&a)const{
        return cost < a.cost;
    }
};
void Init (int n){
    for (int i = 1; i <= n;i++)
    {    f[i] = i;
        sizes[i] = 1;
    }
}
int find(int x){
    if (x==f[x])
        return x;else
    return f[x] = find(f[x]);
}
bool unity(int a,int b){
    int pa = find(a);
    int pb = find(b);
    if (pa==pb)
        return false;
        else if (sizes[pa]>sizes[pb]){
            sizes[pa] += sizes[pb];
            f[pb] = f[pa];
        }
        else {
            sizes[pb] += sizes[pa];
            f[pa] = f[pb];
        }
        return true;
}

vector<node> edge(200005);
int main() {

    cin >> n >> m;
     Init(n);
    for (int i = 1; i <= m;i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edge[i].cost = c, edge[i].start = a, edge[i].to = b;
    }
    sort(edge.begin() + 1, edge.begin() + m + 1);
    //cout << edge[1].cost;
    int cnt = 0, total = 0;
    for (int i = 1; i <= m&&cnt<n-1;i++){
        if (unity(edge[i].start, edge[i].to)){
            total += edge[i].cost;
            cnt++;
        }
    }
    if (cnt==n-1)
    cout << total << endl;
    else
        cout << "orz" << endl;
    return 0;
}