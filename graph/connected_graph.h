#ifndef IHW3_CONNECTED_GRAPH_H
#define IHW3_CONNECTED_GRAPH_H
#include "base_graph.h"

using namespace std;

// Связный граф.
class connected_graph : public base_graph {
public:
    // Генерация связного графа - сначала соединиям все вершины,
    // после этого добавляем случайные ребра.
    connected_graph(int n) : base_graph(n) {
        for (int i = 0; i < n - 1; ++i) {
            graph[i][i + 1] = rand_edge_weight();
            graph[i + 1][i] = graph[i][i + 1];
        }
        int koeff = n * n / 5; // n * n / 2 - максимальное количество ребер. разделим его на 2 чтобы получить примерно 0.5 коэффицент плотности.
        while (koeff > 0) {
            int node_x = rand_node();
            int node_y = rand_node();
            if (node_x == node_y) {
                continue;
            }
            if (graph[node_x][node_y] != INF) {
                continue;
            }
            graph[node_x][node_y] = rand_edge_weight();
            graph[node_y][node_x] = graph[node_x][node_y];
            koeff--;
        }
    }

    int rand_node() {
        return rand() % graph.size();
    }
};


#endif //IHW3_CONNECTED_GRAPH_H
