#include<bits/stdc++.h>

using namespace std;
int n,t;
/*
    多组输入先cin组数
    然后分别处理每组  ！！！输入！！！
    前序遍历就是插入顺序，中序遍历为排序顺序
    3h我的时间=========
    认真读题..
*/
struct avl {
    avl *left, *right;
    int val, height;

//    avl(int val) : val(val), left(nullptr), right(nullptr), height(1) {};
};

int get_h(avl *h) {
    if (!h)return 0;
    else return h->height;
}

void push_up(avl *node) {
  node->height=max(get_h(node->left),get_h(node->right))+1;
}

avl* createNode(int val){
    avl* node = new avl;
    node->val=val;
    node->right= nullptr,node->left= nullptr;
    node->height=1;
    return node;
}


void insert(avl *&node, int val) {
    if (!node) {
//        node = new avl(val);
    node= createNode(val);
    return;
    } else if (val < node->val) {
        insert(node->left, val);
    } else insert(node->right, val);

    push_up(node);
}







void check(avl *&node, int &flag) {


    if (node->left)check(node->left, flag);
    if (node->right)check(node->right, flag);
    if (abs(get_h(node->left) - get_h(node->right)) >= 2) {
        flag = true;
        return;
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin >> t ;
    while (t--) {
        avl *root = nullptr;
        cin>>n;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            insert(root, x);
        }
        int flag=0;
        check(root, flag);
        if (flag) {
            cout << "No" << "\n";
        } else cout << "Yes" << "\n";
    }
}
