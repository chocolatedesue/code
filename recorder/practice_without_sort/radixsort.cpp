#include<iostream>
#include<cmath>
#include<cstring>
#include<cstring>
using namespace std;
int arr[] = { 452, 845, 123, 846, 462, 357, 540, 423 };

int* mysort(int len) {
    int idx = 3;
    int* res = new int[len];
    for (int j = 0; j < idx; j++) {
        int count[10];
        memset(count, 0, sizeof(count));
        for (int i = 0; i < len; i++) {
            int num = arr[i] / (int)pow(10, j) % 10;
            count[num]++;
        }
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
       // int cnt = 0;
        for (int i = len-1; i >=0 ; i--) {
            int num = arr[i] / (int)pow(10, j) % 10;
            res[--count[num]] = arr[i];
        }
      //  for (int i)
        for (int i = 0; i < len; i++) {
            arr[i] = res[i];
        }
    }
    return res;
}

int main() {
    int len = sizeof(arr) / sizeof(arr[0]);
    int *p=mysort(len);

    for (int i = 0; i < len; i++) {
        cout << p[i] << " ";
    }
    return 0;
}