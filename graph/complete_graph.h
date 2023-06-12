#ifndef IHW3_COMPLETE_GRAPH_H
#define IHW3_COMPLETE_GRAPH_H
#include "base_graph.h"

using namespace std;

// Полный граф.
class complete_graph : public base_graph {
public:
    // Генерация полного графа - каждому ребру задается случайный вес.
    complete_graph(int n) : base_graph(n) {
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (i == j) {
                    graph[i][j] = INF;
                    graph[j][i] = INF;
                    continue;
                }

                graph[i][j] = rand_edge_weight();
                graph[j][i] = graph[i][j];
            }
        }
    }
};


#endif //IHW3_COMPLETE_GRAPH_H
