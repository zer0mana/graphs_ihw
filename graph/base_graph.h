#ifndef IHW3_BASE_GRAPH_H
#define IHW3_BASE_GRAPH_H
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

long const INF = 200000;

class base_graph {
public:
    vector<vector<long>> graph;
    int edges_count = 0;

    // Генерация графа, если ребра нет, то INT32_MAX.
    base_graph(int n) {
        graph = vector<vector<long>>(n, vector<long>(n, INF));
    }

    // Случайный целый вес ребра от 1 до 10.
    int rand_edge_weight() {
        return (rand() % 10) + 1;
    }

    // Выводит граф в консоль.
    void print() {
        for (auto i : graph) {
            for (auto j : i) {
                if (j == INF) {
                    cout << "_ ";
                    continue;
                }
                cout << j << " ";
            }
            cout << '\n';
        }
    }
};

#endif //IHW3_BASE_GRAPH_H
