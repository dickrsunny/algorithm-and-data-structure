/*
 使用prim算法生成最小生成树
 */


#include <iostream>

using namespace std;


#define MaxVerticeNum 100
#define MaxDistance 65535


typedef struct {
//    int vertices[MaxVerticeNum];
    int array[MaxVerticeNum][MaxVerticeNum];
    int vertice_num, edge_num;
} Graph;



void FindMinDistance(Graph G, const int min_distances[], const int visited[], int *min_v_p) {
    int min = MaxDistance;
    for(int i=0; i<G.vertice_num; i++) {
        if(visited[i] == 0 && min_distances[i] < min) {
            min = min_distances[i];
            *min_v_p = i;
        }
    }
}


void UpdateMinDistance(Graph G, int min_distances[], int records[], const int visited[], int min_v ) {
    for(int i=0; i<G.vertice_num; i++) {
        if(visited[i] == 0 && G.array[min_v][i] < min_distances[i]) {
            min_distances[i] = G.array[min_v][i];
            records[i] = min_v;
        }
    }
}


void MinSpanTree(Graph G, int v) {
    // v 表示构建生成树开始的顶点
    int records[MaxVerticeNum];  // 保存指向当前顶点的顶点
    int min_distances[MaxVerticeNum];  // 指向当前顶点的顶点（对应于records数组的值）和当前顶点的距离（即边的权值）；

    int visited[MaxVerticeNum];  // 标记顶点是否访问过，0：未访问；1：已访问

    // 初始化数组
    for(int i=0; i<G.vertice_num; i++) {
        min_distances[i] = G.array[v][i];
        records[i] = v;
        visited[i] = 0;
    }

    visited[v] = 1;

    int min_v;
    for(int i=1; i<G.vertice_num; i++) {
        FindMinDistance(G, min_distances, visited, &min_v);  // 找到当前最小权值的点

        cout << records[min_v] << " -> " << min_v << endl;  // 输出当前最小权值的边
        visited[min_v] = 1;  // 标记顶点已访问过

        UpdateMinDistance(G, min_distances, records, visited, min_v);
    }

}


int main() {
    Graph G = {
        {
            {0, 10, 20, 60},
            {10, 0, 50, 40},
            {20, 50, 0, 30},
            {60, 40, 30, 0}
        },
        4
    };
    MinSpanTree(G, 1);

    return 0;
}
