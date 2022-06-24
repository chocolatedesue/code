#include <bits/stdc++.h>
using namespace std;
struct node
{
    int to, cost;
};
int cnt = 0;
struct vertex
{
    int id, dis;
};
struct cmp
{
    bool operator()(const vertex& a, const vertex& b)
    {
        return a.dis > b.dis;
    }
};



priority_queue<vertex, vector<vertex>, cmp> q;
bool collected[10005];

int dist[10005];
vector<node> v[10005];
int n, m, s;
void djsk()
{
    while (1)
    {
        if (q.empty())
            break;
        else
        {
            vertex temp = q.top();
            q.pop();
            int dis = temp.dis;
            int id = temp.id;
            collected[id] = true;
            for (int i = 0; i < v[id].size(); i++)
            {

                if (!collected[v[id][i].to])
                {
                    if (dist[v[id][i].to] > dis + v[id][i].cost)
                    {
                        dist[v[id][i].to] =  dis + v[id][i].cost;
                       // collected[v[id][i].to] = true;
                        q.push({ v[id][i].to, dis+v[id][i].cost});
                        cnt++;
                    }
                }
            }
        }
    }
    // if (cnt==n-1){
    //     return;
    // }
    // else {
    //     for (int i = 1; i <= n;i++){
    //         if ()
    //     }
    // }
}
int main()
{
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)dist[i] = INT_MAX;
    for (int i = 1; i <= m; i++)
    {
        int start, to, cost;
        scanf("%d%d%d", &start, &to, &cost);
        v[start].push_back({ to, cost });
        // q.push(2e9);
    }
    dist[s] = 0;
    q.push({ s, 0 });
    djsk();
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", dist[i]);
    }
    return 0;
}