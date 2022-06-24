#include<bits/stdc++.h>
using namespace std;
unordered_map<int, int> um;
//long long ans = 0;
int s[5];
int dp[605];
int dat[25];
#define MAX 100005
long long ans = 0;
int solve(int num,int w,int min){
    for (int i = 1; i <= num;i++){
        for (int j = w; j >= dat[i];j--){
            if (dat[i]<=j&&dat[i]+dp[j-dat[i]]<=w)
                dp[j] = max(dp[j - dat[i]] + dat[i], dp[j]);
        }
    }
    return max(dp[w],min);
}
int main(){
    cin >> s[1] >> s[2] >> s[3] >> s[4];
    for (int i = 1; i <= 4;i++){
        memset(dat, 0, sizeof(dat));
        memset(dp, 0, sizeof(dp));
        int mins = 1e9,maxs=-1e9;
        int sum = 0;
        for (int j = 1; j <= s[i];j++){
            scanf("%d", &dat[j]);
            sum += dat[j];
            mins = min(dat[j], mins);
            maxs = max(maxs, dat[j]);
        }
        int t;
    if (s[i]==1)
        t = dat[1];

        else if (maxs>=sum/2)
            t = max(maxs, sum - maxs);
            else
         {
             int temp = solve(s[i], sum / 2, mins);
             t = max(temp, sum - temp);
         }
        ans += t;
    }
    cout << ans << endl;
    return 0;
}