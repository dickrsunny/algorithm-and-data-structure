/*
 利用kruskal算法生成最小生成树
 */


#include <iostream>
#include <algorithm>

using namespace std;


#define MaxVerticeNum 100
#define MaxEdgeNum 100


typedef struct {
    int v1, v2;
    int weight;
} Edge;


typedef struct {
//    int vertices[MaxVerticeNum];
    int array[MaxVerticeNum][MaxVerticeNum];
    int vertice_num, edge_num;
} Graph;


void InitializeEdge(Edge edges[]) {
    // 初始化边数组
}


bool Cmp(Edge a, Edge b) {
    return a.weight < b.weight;
}


void InitializeGraph(Graph* G_p) {
    // 初始化图
}


int GetParent(const int parent[], int v) {
    while(parent[v] >= 0) {
        v = parent[v];
    }

    return v;
}


void MinSpanTree(Graph G, const Edge *edges) {
    int parents[MaxVerticeNum];  // 父节点数组及初始化
    for(int i=0; i<G.vertice_num; i++) {
        parents[i] = -1;
    }

    int parent_v1, parent_v2;
    for(int i=0; i<G.edge_num; i++) {
        parent_v1 = GetParent(parents, edges[i].v1);
        parent_v2 = GetParent(parents, edges[i].v2);
        if(parent_v1 != parent_v2) {
            cout<< edges[i].v1 << "->" << edges[i].v2;
            parents[parent_v1] = parent_v2;
        }

    }


}


int main() {
    Edge edges[MaxEdgeNum];
    InitializeEdge(edges);
    sort(edges, edges+MaxEdgeNum, Cmp);  // 按照边的权值进行升序排序

    Graph G;
    InitializeGraph(&G);

    MinSpanTree(G, edges);

    return 0;
}