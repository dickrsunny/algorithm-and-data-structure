/*
1127 ZigZagging on a Tree （30 分）
Suppose that all the keys in a binary tree are distinct positive integers. A unique binary tree can be determined by a given pair of postorder and inorder traversal sequences. And it is a simple standard routine to print the numbers in level-order. However, if you think the problem is too simple, then you are too naive. This time you are supposed to print the numbers in "zigzagging order" -- that is, starting from the root, print the numbers level-by-level, alternating between left to right and right to left. For example, for the following tree you must output: 1 11 5 8 17 12 20 15.

zigzag.jpg

        Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤30), the total number of nodes in the binary tree. The second line gives the inorder sequence and the third line gives the postorder sequence. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print the zigzagging sequence of the tree in a line. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
8
12 11 20 17 1 15 8 5
12 20 17 11 15 8 5 1
Sample Output:
1 11 5 8 17 12 20 15
*/


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/* 定义二叉树 */
typedef struct BiTreeNode {
    int data;
    struct BiTreeNode *left, *right;
} BiTreeNode;


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
