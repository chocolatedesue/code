#include<bits/stdc++.h>
using namespace std;
int n,m,in[1505];//存入度数量
vector<int>g[1505];//存边
vector<int>d[1505];//存边权
queue<int>q;//队列
int v[1505];//存最长路
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int ff,tt,dd;
        cin>>ff>>tt>>dd;
        g[ff].push_back(tt);
        d[ff].push_back(dd);
        in[tt]++;
    }
    for(int i=2;i<=n;i++)
    {
        v[i]=-1e9;
        if(!in[i]) q.push(i);
    }//初始化
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0;i<g[x].size();i++)
            if(!--in[g[x][i]]) q.push(g[x][i]);
        //只有dag有最长路，切记第一遍先干掉不相关的点
    }
    //废弃其他的入度为0的点。
    q.push(1);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0;i<g[x].size();i++)
        {
            if(v[g[x][i]]<v[x]+d[x][i]) v[g[x][i]]=v[x]+d[x][i];//松弛
            if(!--in[g[x][i]]) q.push(g[x][i]);//如果入度为0就加入队列
        }
    }
    if(v[n]==-1e9) cout<<"-1";
    else cout<<v[n];//输出结果
    return 0;
}