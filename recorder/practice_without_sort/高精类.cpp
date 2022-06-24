#include<iostream>
using namespace std;
int n;
#include<string>
#include<cstring>
#define MAX 5000
struct BigInt{
    string temp;
    int data[MAX];
    int lenth;
    void operator=(const string& temp){
        this->temp = temp;
        int len = temp.size();
        for (int i = len - 1; i >= 0;i--){
           this->data[len - i] = temp[i] - '0';
        }
       this->lenth = len;
    }
   string operator+(const BigInt&a){
        int len = max(lenth, a.lenth);
        int ans[MAX + 1];
        memset(ans, 0, sizeof(ans));
        for (int i = 1; i <= len;i++){
            ans[i] += a.data[i] + data[i];
            // ans[i + 1] = ans[i] / 10;
            // ans[i] %= 10;
        }

       len= flatten(len+1,ans);
        string res;
        // if (ans[len]!=0)
        //     len++;
        for (int i = len; i>=1;i--){
            res.push_back(ans[i]+'0');
        }
        return res;
    }
    int flatten(int len,int *arr){
        for (int i=1;i<=len;i++){
            arr[i+1]+=arr[i]/10;
            arr[i]=arr[i]%10;
        }
        while (!arr[len]&&len>1){
            len--;
        }
        return len;
    }
    // void print(){
    //     for (int i = 0; i < lenth;i++){
    //         printf("%d",&)
    //     }
    // }
    string operator*(const BigInt&a){
        int len = max(a.lenth, lenth);
        int ans[MAX];
        for (int i = 1; i <= a.lenth;i++){
            for (int j = 1; j <= lenth;j++){
                ans[i + j - 1] += a.data[i] * data[j];
            }
        }
        //     ans[i] = data[i] * a.data[i];
        // }
        len = flatten(len * 2, ans);
                string res;
        // if (ans[len]!=0)
        //     len++;
        for (int i = len; i>=1;i--){
            res.push_back(ans[i]+'0');
        }
        return res;
    }
    };

    int main(){
        BigInt a,b;
        string t,t2;
        cin>>t>>t2;
        a=t,b=t2;
        cout<<a*b<<endl;
    }