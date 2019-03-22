/*
1020 Tree Traversals （25 分)
Suppose that all the keys in a binary tree are distinct positive integers.
 Given the postorder and inorder traversal sequences, you are supposed to output
 the level order traversal sequence of the corresponding binary tree.

Input Specification:
Each input file contains one test case. For each case, the first line gives
 a positive integer N (≤30), the total number of nodes in the binary tree.
 The second line gives the postorder sequence and the third line gives the
 inorder sequence. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print in one line the level order traversal sequence
 of the corresponding binary tree. All the numbers in a line must be separated
 by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7

Sample Output:
4 1 6 3 5 7 2
*/


#include <iostream>
#include <queue>

using namespace std;


typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;


const int length = 40;


int get_root_pos(int* in_order, int in_left, int in_right, int val) {
    for (int i=in_left; i<=in_right; i++) {
        if (in_order[i] == val) {
            return i;
        }
    }

    return -1;
}


Node* rebuild(int* post_order, int* in_order, int post_left, int post_right, int in_left, int in_right) {
    if (post_left > post_right) {
        return NULL;
    }

    int root_pos = get_root_pos(in_order, in_left, in_right, post_order[post_right]);

    Node* root = NULL;
    root = new Node;
    root->data = post_order[post_right];

    root->left = rebuild(post_order, in_order, post_left, post_left+root_pos-in_left-1, in_left, root_pos-1);
    root->right = rebuild(post_order, in_order, post_left+root_pos-in_left, post_right-1, root_pos+1, in_right);

    return root;
}


void get_data(int* p, int num) {
    while (num--) {
        scanf("%d", p++);
    }
}


void traverse(Node* root) {
    queue<Node*> q;
    q.push(root);

    Node* node = NULL;
    while (!q.empty()) {
        node = q.front();
        q.pop();
        printf("%d", node->data);

        if (node->left != NULL)
            q.push(node->left);

        if (node->right != NULL)
            q.push(node->right);

        if (!q.empty())
            printf(" ");

    }
}


int main() {
    Node* root = NULL;

    int num, in_order[length], post_order[length];

    scanf("%d", &num);
    if (num > 0) {
        get_data(post_order, num);
        get_data(in_order, num);

        root = rebuild(post_order, in_order, 0, num-1, 0, num-1);

        traverse(root);
    }

    return 0;
}