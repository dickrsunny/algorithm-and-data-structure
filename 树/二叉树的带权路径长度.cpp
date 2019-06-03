/*

       1
    /   \
   2     3
  / \    /
 4   5  6

 */


#include <iostream>
#include <queue>
#include <stack>

using namespace std;


typedef struct BiTreeNode{
    int val;
    struct BiTreeNode* left;
    struct BiTreeNode* right;

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

    queue <BiTreeNode*> q;
    q.push(nodes[0]);

    BiTreeNode *node;
    int index = 1;
    while (index < size) {
        node = q.front();
        q.pop();
        q.push(nodes[index++]);
        node->left = q.back();
        q.push(nodes[index++]);
        node->right = q.back();
    }

    *root_p = nodes[0];
}


// 采用先序遍历的思想
void GetWPL(BiTreeNode* root, int* wpl_p, int depth) {
    if(!root)
        return;

    if(!root->left && !root->right) {
        *wpl_p += root->val*depth;
        return;
    }

    if(root->left)
        GetWPL(root->left, wpl_p, depth+1);

    if(root->right)
        GetWPL(root->right, wpl_p, depth+1);
}


// 采用后序非递归遍历的思想
int GetWPL2(BiTreeNode* root) {
    if(!root)
        return 0;

    int wpl = 0;
    stack<BiTreeNode*> s;

    BiTreeNode* node, *last_visit;
    node = root;
    last_visit = nullptr;

    while(node) {
        s.push(node);
        node = node->left;
    }

    while(!s.empty()) {
        node = s.top();

        if(!node->left && !node->right) {
            wpl += node->val*(s.size()-1);
        }

        if(!node->right || last_visit == node->right){
            s.pop();
            last_visit = node;
        }
        else {
            node = node->right;
            while(node){
                s.push(node);
                node = node->left;
            }
        }
    }

    return wpl;
}


void PreOrder(BiTreeNode* root) {
    if(!root)
        return;

    cout << root->val << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}


int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 0};

    BiTreeNode* root;
    Initialize(&root, array, sizeof(array) / sizeof(array[0]));

    int wpl = 0;
    GetWPL(root, &wpl, 0);
    cout << "pre-order" << endl;
    cout << wpl << endl;

    cout << "post-order" << endl;
    cout << GetWPL2(root);
}
