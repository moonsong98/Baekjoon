#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct {
    int w, u, v;

} Edge;

vector<Edge> edge;
vector<int> parent;
vector<int> height;
int V, E;

int Find(int u) {
    if(parent[u] == u) return u;
    return parent[u] = Find(parent[u]);
}

void Union(int u, int v) {
    int parentU = Find(u);
    int parentV = Find(v);

    if(height[parentU] > height[parentV]) {
        int tmp;
        tmp = parentV;
        parentV = parentU;
        parentU = tmp;
    } 
    parent[parentU] = parentV;
    if(height[parentU] == height[parentV]) {
        height[parentV]++;
    }
}

void solve() {
    std::cin >> V >> E;
    for(int i = 0; i < E; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        edge.push_back({w, u, v});
    }
    auto cmp = [](const Edge& e1, const Edge& e2) {
        return e1.w < e2.w;
    };
    std::sort(edge.begin(), edge.end(), cmp);

    parent = vector<int>(V + 1, -1);
    height = vector<int>(V + 1, 0);
    for(int i = 1; i <= V; ++i) {
        parent[i] = i;
    }
    int ans = 0;
    for(int i = 0; i < edge.size(); ++i) {
        int u = edge[i].u;
        int v = edge[i].v;
        if(Find(u) == Find(v)) continue;
        Union(u, v);
        ans += edge[i].w;
    }
    cout << ans << '\n';
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}