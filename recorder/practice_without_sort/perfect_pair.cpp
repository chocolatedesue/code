
//第一次被卡常.....   stl少用 多用替代品
#include<bits/stdc++.h>
using namespace std;
#define MAXN ((int)1e5+5)
int n,k,a[MAXN][15];
//unordered_map<int,list<int>>m;//获取对应的元素  map常数太大..被卡
vector<int>head[2005];
//差分和只是必要条件 用必要值缩小范围 不是充分条件
//最后还是要一个个check
bool isValid(int i,int j){
    int sum = a[i][0]+a[j][0];
    for (int x=1;x<k;++x){
        if (a[i][x]+a[j][x]!=sum)return false;
    }
    return true;
}

int main(){
    cin >> n>>k;
    for (int i=0;i<n;++i){
        for (int j=0;j<k;++j)
           scanf("%d",&a[i][j]);
    }
    int cnt=0;
    for (int i=0;i<n;++i){
        int idx=a[i][k-1]-a[i][0];//获取差分特征值
        for(int j=0;j<head[-idx+1000].size();j++)
            if(isValid(i,head[-idx+1000][j]))
                cnt++;
        head[idx+1000].push_back(i);
    }
    cout<<cnt<<endl;

return 0;
}