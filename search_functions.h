#ifndef IHW3_SEARCH_FUNCTIONS_H
#define IHW3_SEARCH_FUNCTIONS_H
#include <set>
#include <chrono>
#include <queue>

// Алгоритмы поиска.

// Алгоритм Дейкстры через set
// Иточник: https://e-maxx.ru/algo/dijkstra_sparse
pair<int, int64_t> Dijkstra_algorithm_by_set(vector<vector<long>> graph, int n, int x, int y) {
    auto begin = std::chrono::steady_clock::now();

    vector<int> d(n, INF), p(n);
    d[x] = 0;
    set<pair<int, int>> q;
    q.insert(make_pair(d[x], x));
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (size_t j = 0; j < graph[v].size(); ++j) {
            int to = j;
            int len = graph[v][j];

            if (d[v] + len < d[to]) {
                q.erase(make_pair(d[to], to));
                d[to] = d[v] + len;
                p[to] = v;
                q.insert(make_pair(d[to], to));
            }
        }
    }

    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);

    return make_pair(d[y], elapsed_ms.count());
}

// Алгоритм Дейкстры через priority_queue
// Иточник: https://e-maxx.ru/algo/dijkstra_sparse
pair<int, int64_t> Dijkstra_algorithm_by_priority_queue(vector<vector<long>> graph, int n, int x, int y) {
    auto begin = std::chrono::steady_clock::now();

    vector<int> d(n, INF), p(n);
    d[x] = 0;
    priority_queue<pair<int, int>> q;
    q.push(make_pair(d[x], x));
    while (!q.empty()) {
        int v = q.top().second, cur_d = -q.top().first;
        q.pop();

        if (cur_d > d[v]) continue;

        for (size_t j = 0; j < graph[v].size(); ++j) {
            int to = j;
            int len = graph[v][j];

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push(make_pair(-d[to], to));
            }
        }
    }

    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);

    return make_pair(d[y], elapsed_ms.count());
}

// Алгоритм Флойда-Уоршела
// Источник: https://habr.com/ru/articles/119158/
pair<int, int64_t> Floyd_Warshell_algorithm(vector<vector<long>> graph, int n, int x, int y) {
    auto begin = std::chrono::steady_clock::now();

    auto d = graph;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);

    return make_pair(d[x][y], elapsed_ms.count());
}

// Алгоритм Форда-Беллмана
// Иточник: https://ru.wikipedia.org/wiki/Алгоритм_Беллмана_—_Форда
struct edge {
    int a, b, cost;
};

pair<int, int64_t> Ford_Bellman_function(vector<vector<long>> graph, int n, int x, int y) {
    auto begin = std::chrono::steady_clock::now();

    vector<edge> e;
    for (int i = 0 ; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] != INF) {
                e.push_back(edge {i, j, graph[i][j]});
            }
        }
    }

    vector<long> d(n, INF);
    d[x] = 0;
    for (int i = 1; i < n; ++i) {
        for (auto item : e) {
            if (d[item.a] > d[item.b] + item.cost) {
                d[item.a] = d[item.b] + item.cost;
            }
        }
    }

    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);

    return make_pair(d[y], elapsed_ms.count());
}

#endif //IHW3_SEARCH_FUNCTIONS_H
