//
// Created by choco on 2022/2/18.
//
//avl的基础版本
//函数之间指针传递是复制一份指针，不会改变原有指针指向。 但指向的都是一块内存区域
//还是要选择返回值或者引用
//与splay区别  以上面为起点  旋转下面节点  不能神奇的fa操作  老老实实四个旋转
#include<bits/stdc++.h>

using namespace std;

struct avl {
    int val, h;
    avl *left, *right;

    avl(int val) {
        this->val = val, this->h = 1;
        this->left = nullptr, this->right = nullptr;
    }
};


inline int get_height(avl *x) {
    if (!x)return 0;
    else
        return x->h;
}

inline void update_h(avl *node) {
    if (!node->left && !node->right)node->h=1;
    else if (!node->left)node->h = node->right->h + 1;
    else if (!node->right)node->h = node->left->h + 1;
    else
        node->h = max(node->left->h, node->right->h) + 1;
}

avl* left_rotate(avl *node) {
    avl *lson = node->left;
    node->left = lson->right;
    lson->right = node;
    update_h(node);
    update_h(lson);
    return lson;
}

avl* right_rotate(avl *node) {
    avl *rson = node->right;
    node->right = rson->left;
    rson->left = node;
    update_h(node), update_h(rson);
    return rson;
}

avl* left_right_rotate(avl *node) {
   node->left = right_rotate(node->left);
   return  left_rotate(node);
}

avl* right_left_rotate(avl *node) {
   node->right=left_rotate(node->right);
   return  right_rotate(node);
}

avl *insert(avl *node, int val) {
    if (node == nullptr) {
        node = new avl(val);
        return node;
    } else if (node->val >= val) {
        node->left = insert(node->left, val);
        update_h(node);
        if (get_height(node->left) - get_height(node->right) == 2) {
            if (val <= node->left->val)node=left_rotate(node);
            else node=left_right_rotate(node);
        }
    } else {
        node->right = insert(node->right, val);
        update_h(node);
        if (get_height(node->right) - get_height(node->left) == 2) {
            if (val > node->right->val)node=right_rotate(node);
            else node=right_left_rotate(node);
        }

    }
    return node;
}

int n;

int main() {
    avl *root = nullptr;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        root = insert(root, t);
    }
    cout << root->val << endl;
}

