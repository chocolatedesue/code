#include<bits/stdc++.h>
using namespace std;
int n;
#define MAXN 1005
typedef long long ll;
//int a[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin >> n;

    while (n--) {
        string temp;
        int k;
        cin >> temp >> k;
        int idx;
        int t = k;
        int len = temp.size();
        for (int i = 0; t!=0; i++) {
            if (i != len) {
                int min = temp[i] - '0'; idx = i;
            
                for (int j = i + 1; j <= i + t && j < len; j++) {
                    if (min > temp[j] - '0') {
                        min = temp[j] - '0', idx = j;
                        //cout << "flag " << min << " " << idx<<endl;
                    }
                }temp.erase(i, idx - i); t -= idx - i; len -= idx - i;
            }
            else {
                while (t--) {
                    temp.erase(temp.begin() + len - 1);
                    len--;
                }t++;
            }
            
        }
        cout << temp << endl;
    }

}