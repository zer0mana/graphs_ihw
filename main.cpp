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
const int ATTEMPTS = 5;
std::ofstream out;

void tester(std::function<pair<int, long long>(vector<vector<long>> graph, int n, int x, int y)> func, string func_name) {
    out << func_name << '\n';
    out << "complete_graph" << '\n';

    out << "nodes;edges;time" << '\n';
    for (int i = 10; i <= ITERATIONS; i += STEP) {
        complete_graph cg(i);
        out << i << ';' << cg.edges_count << ';';

        long long final_time = 0;
        for (int j = 0; j < ATTEMPTS; ++j) {
            final_time = func(cg.graph, i, 0, i - 1).second;
        }
        final_time /= ATTEMPTS;
        out << final_time << '\n';
    }

    out << '\n' << "connected_graph" << '\n';
    out << "nodes;edges;time" << '\n';
    for (int i = 10; i <= ITERATIONS; i += STEP) {
        connected_graph cn(i);
        out << i << ';' << cn.edges_count << ';';

        long long final_time = 0;
        for (int j = 0; j < ATTEMPTS; ++j) {
            final_time = func(cn.graph, i, 0, i - 1).second;
        }
        final_time /= ATTEMPTS;
        out << final_time << '\n';
    }

    out << '\n' << "sparse_graph" << '\n';
    out << "nodes;edges;time" << '\n';
    for (int i = 10; i <= ITERATIONS; i += STEP) {
        sparse_graph sg(i);
        out << i << ';' << sg.edges_count << ';';

        long long final_time = 0;
        for (int j = 0; j < ATTEMPTS; ++j) {
            final_time = func(sg.graph, i, 0, i - 1).second;
        }
        final_time /= ATTEMPTS;
        out << final_time << '\n';
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
