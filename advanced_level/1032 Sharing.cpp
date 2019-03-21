/*
1032 Sharing （25 分)
To store English words, one method is to use linked lists and store a word letter by letter.
 To save some space, we may let the words share the same sublist if they share the same suffix.
 For example, loading and  being are stored as showed in Figure 1.

fig.jpg

Figure 1

You are supposed to find the starting position of the common suffix (e.g. the position of i in Figure 1).

Input Specification:
Each input file contains one test case. For each case, the first line contains two addresses of nodes and a positive N (≤10
​5
​​ ), where the two addresses are the addresses of the first nodes of the two words, and N is the total number of nodes.
 The address of a node is a 5-digit positive integer, and NULL is represented by −1.

Then N lines follow, each describes a node in the format:

Address Data Next
whereAddress is the position of the node, Data is the letter contained by this node which is an English
 letter chosen from { a-z, A-Z }, and Next is the position of the next node.

Output Specification:
For each case, simply output the 5-digit starting position of the common suffix. If the two words
 have no common suffix, output -1 instead.

Sample Input 1:
11111 22222 9
67890 i 00002
00010 a 12345
00003 g -1
12345 D 67890
00002 n 00003
22222 B 23456
11111 L 00001
23456 e 67890
00001 o 00010

Sample Output 1:
67890

Sample Input 2:
00001 00002 4
00001 a 10001
10001 s -1
00002 a 10002
10002 t -1

Sample Output 2:
-1
 */


// solution 1 24' 未通过一个测试用例

#include <cstdio>
#include <map>

using namespace std;


typedef struct Node {
    int address;
    char data;
    int next_address;
    bool flag;
} Node;


map<int, Node*> addr_node;


Node* initialize() {
    Node* node = new Node;
    scanf("%d %c %d", &node->address, &node->data, &node->next_address);
    node->flag = false;
    return node;
}


void find_common_node() {
    int addr1, addr2;
    int num;
    scanf("%d %d %d", &addr1, &addr2, &num);

    while (num--) {
        Node* node;
        node = initialize();
        addr_node[node->address] = node;
    }

    Node* node1 = addr_node[addr1];
    while (node1->next_address != -1) {
        node1->flag = true;
        node1 = addr_node[node1->next_address];
    }

    Node* node2 = addr_node[addr2];
    while (node2->next_address != -1) {
        if (node2->flag) {
            printf("%05d", node2->address);
            return;
        }

        node2 = addr_node[node2->next_address];
    }

    printf("%d", -1);
}


int main() {
    find_common_node();
    return 0;
}


/*
#include <cstdio>

using namespace std;

struct NODE {
    char key;
    int next;
    bool flag;
}node[100000];

int main() {
    int s1, s2, n, a, b;
    scanf("%d%d%d", &s1, &s2, &n);
    char data;
    for(int i = 0; i < n; i++) {
        scanf("%d %c %d", &a, &data, &b);
        node[a] = {data, b, false};
    }
    for(int i = s1; i != -1; i = node[i].next)
        node[i].flag = true;
    for(int i = s2; i != -1; i = node[i].next) {
        if(node[i].flag == true) {
            printf("%05d", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}
*/