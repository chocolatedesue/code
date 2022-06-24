/*
 * 1. 区分无向图和有向图 (邻接表如何存储多个数据)
 * 2. 将判断的接口拆分  （判断是否为质数因子，是否为已经访问的点）
 * 3. stl 小于改大于的技巧
 * 4. 步骤 :
        1. 维护小树集合(vis)
        2. 小根堆取点(priority_queue)
        3. 更新距离
 */

#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int)5e3+5)
int n, m;
int cnt=0;
struct node {
    int w, to;
    // bool operator < (const node& b)const{
    //     return w>=b.w;
    // }
};
struct cmp{
    bool operator() (node a,node b){
        return a.w > b.w;
    }
};

vector <vector<node> >v(MAXN);
long long ans=0;
//将是否已经访问过换一个接口判断不然不好设计
int vis[MAXN];
//priority_queue<node,vector<node>,greater<> >q;
priority_queue<node,vector<node>,cmp >q;
int dist[MAXN];
void Prim(){
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;
    q.push({0,1});
    while (!q.empty()&&cnt<n){
        int d=q.top().w,from=q.top().to;
        q.pop();
        if (vis[from])continue;
        vis[from]=1,ans+=d;
        cnt+=1;
        for (int i=0;i<v[from].size();++i){
            if (v[from][i].w<dist[v[from][i].to])
                dist[v[from][i].to]=v[from][i].w;
                q.push({v[from][i].w,v[from][i].to});
        }

    }

}

void add(int w, int from, int to) {
    v[from].push_back({w, to});
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int start, end, dis;
        scanf("%d%d%d", &start, &end, &dis);
        add(dis, start, end);
        add(dis,end,start);
    }
    Prim();
    if (cnt!=n)cout<<"orz"<<endl;
    else cout<<ans<<endl;
    return 0;
}
/*
 * 1. 区分无向图和有向图
 * 2. 将判断的接口拆分  （判断是否为质数因子，是否为已经访问的点）
 * 3. stl 小于改大于的技巧
 */

#include <bits/stdc++.h>
using namespace std;
#define MAXN ((int)5e3+5)
int n, m;
int cnt=0;
struct node {
    int w, to;
    bool operator < (const node& b)const{
        return w>=b.w;
    }
};

vector<vector<node>>v(MAXN);
long long ans=0;
//将是否已经访问过换一个接口判断不然不好设计
int vis[MAXN];
//priority_queue<node,vector<node>,greater<> >q;
priority_queue<node >q;
int dist[MAXN];
void Prim(){
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;
    q.push({0,1});
    while (!q.empty()&&cnt<n){
        int d=q.top().w,from=q.top().to;
        q.pop();
        if (vis[from])continue;
        vis[from]=1,ans+=d;
        cnt+=1;
        for (int i=0;i<v[from].size();++i){
            if (v[from][i].w<dist[v[from][i].to])
                dist[v[from][i].to]=v[from][i].w;
                q.push({v[from][i].w,v[from][i].to});
        }

    }

}

void add(int w, int from, int to) {
    v[from].push_back({w, to});
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int start, end, dis;
        scanf("%d%d%d", &start, &end, &dis);
        add(dis, start, end);
        add(dis,end,start);
    }
    Prim();
    if (cnt!=n)cout<<"orz"<<endl;
    else cout<<ans<<endl;
    return 0;
}
