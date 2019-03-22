/*
1053 Path of Equal Weight （30 分)
Given a non-empty tree with root R, and with weight W
​i
​​  assigned to each tree node T
​i
​​ . The weight of a path from R to L is defined to be the sum of the weights of all the nodes along the path from R to any leaf node L.

Now given any weighted tree, you are supposed to find all the paths with their weights equal to a given number.
 For example, let's consider the tree showed in the following figure:
 for each node, the upper number is the node ID which is a two-digit number,
 and the lower number is the weight of that node. Suppose that the given number is 24,
 then there exists 4 different paths which have the same given weight: {10 5 2 7}, {10 4 10}, {10 3 3 6 2}
 and {10 3 3 6 2}, which correspond to the red edges in the figure.



Input Specification:
Each input file contains one test case. Each case starts with a
 line containing 0<N≤100, the number of nodes in a tree,
 M (<N), the number of non-leaf nodes, and 0<S<2
​30
​​ , the given weight number. The next line contains N positive numbers where W
​i
​​  (<1000) corresponds to the tree node T
​i
​​ . Then M lines follow, each in the format:

ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a given non-leaf node,
 K is the number of its children, followed by a sequence of two-digit
 ID's of its children. For the sake of simplicity, let us fix the root ID to be 00.

Output Specification:
For each test case, print all the paths with weight S in
 non-increasing order. Each path occupies a line with printed weights
 from the root to the leaf in order. All the numbers must be separated
 by a space with no extra space at the end of the line.

Note: sequence {A
​1
​​ ,A
​2
​​ ,⋯,A
​n
​​ } is said to be greater than sequence {B
​1
​​ ,B
​2
​​ ,⋯,B
​m
​​ } if there exists 1≤k<min{n,m} such that A
​i
​​ =B
​i
​​  for i=1,⋯,k, and A
​k+1
​​ >B
​k+1
​​ .

Sample Input:
20 9 24
10 2 4 3 5 10 2 18 9 7 2 2 1 3 12 1 8 6 2 2
00 4 01 02 03 04
02 1 05
04 2 06 07
03 3 11 12 13
06 1 09
07 2 08 10
16 1 15
13 3 14 16 17
17 2 18 19

Sample Output:
10 5 2 7
10 4 10
10 3 3 6 2
10 3 3 6 2
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


typedef struct Node {
    int weight;
    vector<int> next;
} Node;


Node nodes[110];


void get_right_weights(Node node, int total_weight, vector<vector<int>>* right_weights_addr, vector<int> weight_path) {
    weight_path.push_back(node.weight);

    if (node.next.size() == 0) {
        int sum = 0;
        for (int i=0; i<weight_path.size(); i++) {
            sum += weight_path[i];
        }

        if (sum == total_weight) {
            right_weights_addr->push_back(weight_path);
        }

        return;
    }

    for (int i=0; i<node.next.size(); i++) {
        get_right_weights(nodes[node.next[i]], total_weight, right_weights_addr, weight_path);
    }
}


void traverse(vector<vector<int>> right_weights) {
    for (int i=0; i<right_weights.size(); i++) {
        for (int j=0; j<right_weights[i].size()-1; j++) {
            printf("%d ", right_weights[i][j]);
        }

        printf("%d\n", right_weights[i][right_weights[i].size()-1]);
    }
}


bool cmp(vector<int> right_weight1, vector<int> right_weight2) {
    int i = 0, j = 0;
    for (; i<right_weight1.size() and j<right_weight2.size(); i++, j++) {
        if (right_weight1[i] != right_weight2[j]) {
            return right_weight1[i] > right_weight2[j];
        }
    }

    if (i==right_weight1.size()-1 and j==right_weight2.size()-1)
        return true;
    else
        return i < right_weight1.size() - 1;
}


int main() {
    int nodes_num, non_leaf_nodes_num, total_weight;
    scanf("%d %d %d", &nodes_num, &non_leaf_nodes_num, &total_weight);

    for (int i=0; i<nodes_num; i++) {
        scanf("%d", &nodes[i].weight);
    }

    while (non_leaf_nodes_num--) {
        int seq, children_nums;
        scanf("%d %d", &seq, &children_nums);

        int child_seq;
        for (int i=0; i<children_nums; i++) {
            scanf("%d", &child_seq);
            nodes[seq].next.push_back(child_seq);
        }
    }

    vector<vector<int>> right_weights;
    vector<int> weight_path;

    get_right_weights(nodes[0], total_weight, &right_weights, weight_path);

    sort(right_weights.begin(), right_weights.end(), cmp);

    traverse(right_weights);

    return 0;
}
