#include <iostream>
#include "graph/complete_graph.h"
#include "graph/connected_graph.h"
#include "graph/sparse_graph.h"
#include "search_functions.h"
#include <fstream>
#include <functional>

const string PATH = "../output.csv";
const int ITERATIONS = 1010;
const int STEP = 50;
std::ofstream out;

void tester(std::function<pair<int, long long>(vector<vector<long>> graph, int n, int x, int y)> func, string func_name) {
    out << func_name << '\n';
    out << "complete_graph" << '\n';
    for (int i = 10; i <= ITERATIONS; i += STEP) {
        complete_graph cg(i);
        out << func(cg.graph, i, 0, i - 1).second << ';';
    }
    out << '\n' << "connected_graph" << '\n';
    for (int i = 10; i <= ITERATIONS; i += STEP) {
        connected_graph cn(i);
        out << func(cn.graph, i, 0, i - 1).second << ';';
    }
    out << '\n' << "sparse_graph" << '\n';
    for (int i = 10; i <= ITERATIONS; i += STEP) {
        sparse_graph sg(i);
        out << func(sg.graph, i, 0, i - 1).second << ';';
    }
}

int main() {
    srand(time(NULL));
    out.open(PATH);

    tester(Dijkstra_algorithm, "Dijkstra_algorithm");
    out << '\n';
    tester(Floyd_Warshell_algorithm, "Floyd_Warshell_algorithm");
    out << '\n';
    tester(Ford_Bellman_function, "Ford_Bellman_function");

    out.close();
}
