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


void PreOrder(BiTreeNode* root) {
    if(!root)
        return;

    cout << root->val << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}


void PreOrderNonRecursive(BiTreeNode* root) {
    if(!root)
        return;

    stack<BiTreeNode*> s;
    s.push(root);

    BiTreeNode* node;
    while(!s.empty()) {
        node = s.top();
        cout << node->val << " ";
        s.pop();

        if (node->right)
            s.push(node->right);

        if (node->left)
            s.push(node->left);
    }
}


void PreOrderNonRecursive2(BiTreeNode* root) {
    if(!root)
        return;

    stack<BiTreeNode*> s;

    BiTreeNode* node = root;

    while(node || !s.empty()) {
        if(node) {
            cout << node->val << " ";
            s.push(node);
            node = node->left;
        }
        else {
            node = s.top();
            s.pop();
            node = node->right;
        }
    }
}


void InOrder(BiTreeNode* root) {
    if(!root)
        return;

    InOrder(root->left);
    cout << root->val << " ";
    InOrder(root->right);
}


void InOrderNonRecursive(BiTreeNode* root) {
    if(!root)
        return;

    stack<BiTreeNode*> s;

    BiTreeNode* node = root;

    while(node || !s.empty()) {
        if(node) {
            s.push(node);
            node = node->left;
        }
        else {
            node = s.top();
            cout << node->val << " ";
            s.pop();
            node = node->right;
        }
    }
}


void PostOrder(BiTreeNode* root) {
    if(!root)
        return;

    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->val << " ";
}


void PostOrderNonRecursive(BiTreeNode* root) {
    if(!root)
        return;

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

        if(!node->right || last_visit == node->right){
            s.pop();
            cout << node->val << " ";
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


int MaxDepth(BiTreeNode* root) {
    if(!root)
        return 0;

    int left_depth = MaxDepth(root->left);
    int right_depth = MaxDepth(root->right);

    return max(left_depth, right_depth) + 1;
}


bool IsSameTree(BiTreeNode* root1, BiTreeNode* root2) {
    if(!root1 && !root2) {
        return true;
    }

    else if(root1 && root2) {
        return root1 == root2 && IsSameTree(root1->left, root2->left) && IsSameTree(root1->right, root2->right);
    }

    else
        return false;
}


void Swap(BiTreeNode* root) {
    if(!root)
        return;

    Swap(root->left);
    Swap(root->right);

    BiTreeNode* node;
    node = root->left;
    root->left = root->right;
    root->right = node;
}


int KthNode(BiTreeNode* root, int k, int* count) {
    if(!root)
        return 0;

    *count += 1;
    if(*count == k) {
        return root->val;
    }

    int l_val = KthNode(root->left, k, count);

    return l_val? l_val: KthNode(root->right, k, count);
}


int main() {
    int array[] = { 1, 2, 3, 4, 0, 5, 6, 0, 7 };

    BiTreeNode* root;
    Initialize(&root, array, sizeof(array) / sizeof(array[0]));

    cout << "pre-order recursive" << endl;
    PreOrder(root);
    cout << endl << "pre-order non recursive" << endl;
    PreOrderNonRecursive2(root);

    cout << endl << "in-order recursive" << endl;
    InOrder(root);
    cout << endl << "in-order recursive" << endl;
    InOrderNonRecursive(root);

    cout << endl << "post-order recursive" << endl;
    PostOrder(root);
    cout << endl << "post-order non recursive" << endl;
    PostOrderNonRecursive(root);

    cout << endl << "level traverse" << endl;
    LevelTraverse(root);

    cout << endl << "max depth" << endl;
    cout << MaxDepth(root);

    cout << endl << "is same tree" << endl;
    cout << IsSameTree(root, root);

    cout << endl << "kth node's val" << endl;
    int count = 0;
    cout << KthNode(root, 5, &count);

    cout << endl << "swap left and right" << endl;
    Swap(root);

    cout << endl << "level traverse" << endl;
    LevelTraverse(root);
}