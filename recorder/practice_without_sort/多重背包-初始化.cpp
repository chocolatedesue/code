#include<bits/stdc++.h>
using namespace std;
int n,vt,v[1005],w[1005],dp[1005][1005];
int main(){
    cin>>n>>vt;
    for (int i=1;i<=n;++i)cin>>w[i]>>v[i];//w为体积,v为价值
    for (int i=1;i<=n;++i){
        for (int j=0;j<=vt;++j){
           
            if (j>=w[i])
            dp[i][j]=max(dp[i-1][j],dp[i][j-w[i]]+v[i]);
            else dp[i][j]=dp[i-1][j];
        }
       
    }
//      for (int i=1;i<=n;++i){for(int j=1;j<=vt;++j)cout<<dp[i][j]<<" ";cout<<endl;}
    cout<<dp[n][vt]<<endl;
    memset(dp,-0x3f,sizeof(dp));
    dp[0][0]=0;
    for (int i=0;i<=n;++i)dp[i][0]=0;
    for (int i=1;i<=n;++i){
        for (int j=0;j<=vt;++j){
            if (j>=w[i])
            dp[i][j]=max(dp[i-1][j],dp[i][j-w[i]]+v[i]);
            else dp[i][j]=dp[i-1][j];
        }
        
    }
//     for (int i=1;i<=n;++i){for(int j=1;j<=vt;++j)cout<<dp[i][j]<<" ";cout<<endl;}
    if (dp[n][vt]>0)
    cout<<dp[n][vt]<<endl;
    else cout<<0;
    
}