/*
 使用floyd构建图中任意一对顶点的最短路径
 */


#include <iostream>

using namespace std;


#define MaxVerticeNum 5


typedef struct {
//    int vertices[MaxVerticeNum];
    int array[MaxVerticeNum][MaxVerticeNum];
    int vertice_num, edge_num;
} Graph;


void Floyd(Graph G) {

    int vertices[MaxVerticeNum][MaxVerticeNum];  // 存储顶点的二维数组
    int paths[MaxVerticeNum][MaxVerticeNum];  // 存储最短路径

    // 初始化
    for(int i=0; i<G.vertice_num; i++) {
        for(int j=0; j<G.vertice_num; j++) {
            vertices[i][j] = G.array[i][j];
            paths[i][j] = -1;
        }
    }

    for(int k=0; k<G.vertice_num; k++) {
        for(int i=0; i<G.vertice_num; i++) {
            for(int j=0; j<G.vertice_num; j++) {
                if(vertices[i][k] + vertices[k][j] < vertices[i][j]) {
                    vertices[i][j] = vertices[i][k] + vertices[k][j];
                    paths[i][j] = k;
                }
            }
        }
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

    Floyd(G);
}