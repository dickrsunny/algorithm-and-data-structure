#include <iostream>

using namespace std;


typedef struct node {
    int num;
    struct node* next;
} node;


bool _is_empty(node* node_) {
    return node_ == NULL;
}


node* initialize(int num) {
    node* p = NULL;
    // 动态分配节点内存，相当于 &{0, NULL}
    p = (node*) malloc(sizeof(node));
    if (_is_empty(p)) {
        // 分配失败
        cout << "Initializing node fails";
    }
    else {
        p->num = num;
        p->next = NULL;
    }

    return p;
}



int add(node** head_addr, int num) {
    node* node_ = initialize(num);
    if (_is_empty(node_)) return -1;

    if (_is_empty(* head_addr)) * head_addr = node_;
    else {
        node_->next = * head_addr;
        (* head_addr) = node_;
    }

    return 0;
}


int remove(node** head_addr) {
    if (_is_empty(* head_addr)) return -1;

    node* next_ = (* head_addr)->next;
    free(* head_addr);
    * head_addr = next_;

    return 0;
}


void traverse(node * head ) {
    cout << "-------------" << endl;
    while (head) {
        cout << head->num << endl;
        head = head->next;
    }
    cout << "-------------" << endl;
}


void release(node* head) {
    node* p = NULL;
    while (head) {
        p = head;
        head = head->next;
        free(p);
    }

    cout << "release is done" << endl;
}


int main() {
    // 需要修改head指针的地址
    node* head = NULL;

    add(&head, 1);
    add(&head, 2);
    add(&head, 3);
    traverse(head);

    remove(&head);
    traverse(head);
    remove(&head);
    remove(&head);
    add(&head, 4);
    add(&head, 5);
    add(&head, 6);
    traverse(head);

    release(head);
    return 0;
}
