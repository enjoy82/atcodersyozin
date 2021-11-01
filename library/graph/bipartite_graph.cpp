using Graph = vector<vector<ll>>;
int colors[100005];
bool is_bipartite_graph(const Graph &graph, int v, int c) {
    colors[v] = c;
    for (int u: graph[v]) {
        if (colors[u] == c) {
            return false;
        }
        if (colors[u] == 0 && !is_bipartite_graph(graph, u, -c)) {
            return false;
        }
    }
    return true;
}