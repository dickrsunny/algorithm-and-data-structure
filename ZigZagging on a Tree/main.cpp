#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/* 定义二叉树 */
struct BiTreeNode {
    int data;
    struct BiTreeNode *left, *right;
};


vector<int> in, post;


// 重构二叉树
BiTreeNode* rebuild(int inLeft, int inRight, int postLeft, int postRight) {
    if (inLeft > inRight) return NULL;

    BiTreeNode* root;
    root->data = post[postRight];

    int i = 0;
    while (in[i] != post[postRight]) i++;

    root->left = rebuild(inLeft, i - 1, postLeft, postLeft + (i - inLeft) - 1);
    root->right = rebuild(i + 1, inRight, postLeft + (i - inLeft), postRight - 1);
    return root;
}

// 遍历二叉树
void post_order_traverse(BiTreeNode* root) {
    if (!root) return;

    post_order_traverse(root->left);
    post_order_traverse(root->right);

    cout << root->data << " ";

}


// 广度遍历二叉树
void level_order_traverse(BiTreeNode* root) {
    queue<BiTreeNode*> q;
    q.push(root);

    BiTreeNode* node = root;
    // 存储每一层节点
    vector <BiTreeNode*> temp;
    bool flag = true;

    while (!q.empty()) {
        root = q.front();
        q.pop();

        temp.push_back(root);

        if (root->left) q.push(root->left);
        if (root->right) q.push(root->right);

        if (root->data == node->data) {
            // 输入除了最后一个元素
            if (flag) {
                for (int i = temp.size() - 1; i > 0; i--) cout << temp[i]->data << " ";
            }
            else {
                for (int i = 0; i < temp.size() - 1; i++) cout << temp[i]->data << " ";
            }

            // 判断是否遍历完成
            if (q.empty()) {
                if (flag) cout << temp[0]->data;
                else cout << temp[temp.size() - 1]->data;
                return;
            }
            else {
                if (flag) cout << temp[0]->data << " ";
                else cout << temp[temp.size() - 1]->data << " ";
            }

            flag = !flag;
            temp.clear();
            node = q.back();
        }

    }
}


int main() {
    int n;

    cin >> n;

    in.resize(n), post.resize(n);

    for (int i = 0; i < n; i++) cin >> in[i];
    for (int i = 0; i < n; i++) cin >> post[i];

    BiTreeNode* root;

    root = rebuild(0, n - 1, 0, n - 1);

//    post_order_traverse(root);

    level_order_traverse(root);

    return 0;
}






