
/*

     1
    / \
   2   3
  /   / \
 4   5  6
  \
   7

 */

#include <iostream>
#include <queue>

using namespace std;


typedef struct BiTreeNode{
    int val;
    BiTreeNode* left;
    BiTreeNode* right;

    explicit BiTreeNode(int ele) {
        val = ele;
        left = nullptr;
        right = nullptr;
    }
} BiTreeNode;



void Initialize(BiTreeNode** root_p, const int elements[], int size) {
    if (size < 1) {
        *root_p = nullptr;
    }

    //动态申请size大小的指针数组
    BiTreeNode **nodes;
    nodes = new BiTreeNode* [size];

    //将int数据转换为TreeNode节点
    for (int i = 0; i < size; i++) {
        if (elements[i] == 0) {
            nodes[i] = nullptr;
        } else {
            nodes[i] = new BiTreeNode(elements[i]);
        }
    }

    int i = 0, j = 0;
    while(j < size) {
        if(elements[i]) {
            if(nodes[j+1]) {
                nodes[i]->left = nodes[j+1];
            }

            if(nodes[j+2]) {
                nodes[i]->right = nodes[j+2];
            }
        }
        i++;
        j += 2;
    }

    *root_p = nodes[0];
}


void Release(BiTreeNode* root) {
    if(!root)
        return;

    Release(root->left);
    Release(root->right);

    delete(root);
}


BiTreeNode* DeleteNodeK(BiTreeNode* root, int k) {
    if(!root)
        return nullptr;

    root->left = DeleteNodeK(root->left, k);
    root->right = DeleteNodeK(root->right, k);

    if(root->val == k) {
        Release(root);
        return nullptr;
    }

    return root;
}


void LevelTraverse(BiTreeNode* root) {
    queue<BiTreeNode*> q;
    q.push(root);

    BiTreeNode* node;
    while(!q.empty()) {
        node = q.front();
        cout << node->val << " ";
        q.pop();

        if(node->left) {
            q.push(node->left);
        }

        if(node->right) {
            q.push(node->right);
        }
    }
}


int main() {
    int array[] = { 1, 2, 3, 4, 0, 5, 6, 0, 7 };

    BiTreeNode* root;
    Initialize(&root, array, sizeof(array) / sizeof(array[0]));

    DeleteNodeK(root, 3);

    LevelTraverse(root);
}