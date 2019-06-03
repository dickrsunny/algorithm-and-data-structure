
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
    bool ltag; // true 表示有左子树；false表示无
    bool rtag; // true 表示有右子树；false表示无

    explicit BiTreeNode(int ele) {
        val = ele;
        left = nullptr;
        right = nullptr;
        ltag = false;
        rtag = false;
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
                nodes[i]->ltag = true;
            }
            else {
                nodes[i]->ltag = false;
            }

            if(nodes[j+2]) {
                nodes[i]->right = nodes[j+2];
                nodes[i]->rtag = true;
            }
            else {
                nodes[i]->rtag = false;
            }
        }

        i++;
        j += 2;
    }

    *root_p = nodes[0];
}


void InThread(BiTreeNode** root_p, BiTreeNode** pre_p) {
    if(!*root_p)
        return;

    InThread(&(*root_p)->left, pre_p);
    if(!(*root_p)->ltag) {
        (*root_p)->left = *pre_p;
    }

    if(*pre_p && !(*pre_p)->rtag) {
        (*pre_p)->right = *root_p;
    }

    *pre_p = *root_p;
    InThread(&(*root_p)->right, pre_p);
}


void BuildInThread(BiTreeNode** root_p) {
    BiTreeNode* pre;
    pre = nullptr;
    InThread(root_p, &pre);
}


BiTreeNode* FirstNode(BiTreeNode* root) {
    while(root->ltag)
        root = root->left;

    return root;
}


BiTreeNode* NextNode(BiTreeNode* node) {
    if(!node->rtag)
        return node->right;

    return FirstNode(node->right);
}


void InOrderNonRecursive(BiTreeNode* root) {
    for(root=FirstNode(root); root; root=NextNode(root))
        cout << root->val << " ";
}

void PreOrder(BiTreeNode* root) {
    if(!root)
        return;

    cout << root->val << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}


int main() {
    int array[] = { 1, 2, 3, 4, 0, 5, 6, 0, 7 };

    BiTreeNode* root;
    Initialize(&root, array, sizeof(array) / sizeof(array[0]));

    BuildInThread(&root);

    InOrderNonRecursive(root);
}

