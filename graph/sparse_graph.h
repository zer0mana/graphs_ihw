#ifndef IHW3_SPARSE_GRAPH_H
#define IHW3_SPARSE_GRAPH_H
#include "base_graph.h"

using namespace std;

// Разреженный граф.
class sparse_graph : public base_graph {
public:
    // Строим обычное дерево
    // со случайным количеством наследников
    // у каждого узла.
    sparse_graph(int n) : base_graph(n) {
        int nodes_count = n;
        int current = 0;
        int target = 1;

        while (nodes_count != 0) {
            int nodes = rand_nodes_count();
            while (--nodes > 0 && --nodes_count > 0) {
                graph[current][target] = rand_edge_weight();
                graph[target][current] = graph[current][target];
                target++;
            }
            current++;
        }
    }

    // Случайное количество наследников для узла.
    int rand_nodes_count() {
        return (rand() % 4) + 2;
    }

    // Сделать проверку отсутствия циклов в дереве.
};


#endif //IHW3_SPARSE_GRAPH_H
