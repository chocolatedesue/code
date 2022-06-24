//L2-038 病毒溯源 (25 分) https://pintia.cn/problem-sets/994805046380707840/problems/1386335159927652361
//bfs 比dfs稍微慢一点 （常数太大？）
#include<bits/stdc++.h>
using namespace std;
int n;
const int N = 1e5+10;
vector<int>v[N];
int path[N],mark[N];
struct node{
    int idx,times;
};
int tt[N];


vector<int>ff;
int main(){
    cin>>n;
    for (int i=0;i<n;++i){
        int k;
        cin>>k;
        for (int j=0;j<k;++j){

            int t;
            cin>>t;
            v[i].push_back(t);
            mark[t]=1;
        }

    }
    for (int i=0;i<n;++i){
        if (!mark[i])ff.push_back(i);
    }
    for (int i=0;i<=n;++i)path[i]=i;
    queue<node>q;
    for (int i=0;i<ff.size();++i){
        q.push({ff[i],1});
        tt[ff[i]]=1;
    }

    while (!q.empty()){
        auto x = q.front();
        q.pop();
        int f = x.idx,dis=x.times;
        for (int i=0;i<v[f].size();++i){
            path[v[f][i]]=f;
            q.push({v[f][i],dis+1});
            tt[v[f][i]]=dis+1;
        }
    }
    int mx = 1;
    for (int i=0;i<n;++i){
        mx  = max(mx,tt[i]);
    }
//     int cnt =0;
    vector<int>vv;
    for (int i=0;i<n;++i){
        if (tt[i]==mx){
//             cnt++;
            vv.push_back(i);
        }
    }
    deque<int>ans;
    for (int i=0;i<vv.size();++i){
        int px = vv[i];
        deque<int>temp;
        while (px!=path[px]){
            temp.push_front(px);
            px= path[px];
        }
        temp.push_front(px);
        if (ans.empty()){
            ans = temp;
        }
        else {
            //序列容器和字符串的特殊比较规则
            if (temp<ans)ans = temp;
        }
    }
    cout<<mx<<endl;
    cout<<ans[0];
    for (int i=1;i<mx;++i){
        cout<<" "<<ans[i];
    }

    //字符串无法进行10以上的排序....
//    string ans = "";
//    for (int i=0;i<vv.size();++i){
//        int px = vv[i];
//        string temp="";
//        while (px!=path[px]){
//            temp.push_back(px+'0');
//            px = path[px];
//        }
//        temp.push_back(px+'0');
//        if (ans=="")ans=temp;
//        else {
//                if (!cmp(ans,temp)){
//                    ans = temp;
//                }
//        }
//    }
//    cout<<mx<<endl;
//    cout<<ans[ans.size()-1];
//    for (int i=ans.size()-2;i>=0;--i){
//        cout<<" "<<ans[i];
//    }



    return 0;
}