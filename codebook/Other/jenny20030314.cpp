#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
};
vector<Edge> edges;
vector<vector<Edge>> adj;
vector<int> dist;

// Bellman-Ford子過程
bool BellmanFord(vector<Edge> &edges, int n, int s) {
    dist.resize(n+1, INT_MAX);
    dist[s] = 0;
    bool negtiveCycle;
    for(int i = 1; i <= n; ++i) {
        negtiveCycle = false;
        for(auto e: edges) {
            if(dist[e.u] < INT_MAX && dist[e.v] > dist[e.u] + e.w) {
                dist[e.v] = dist[e.u] + e.w;
                negtiveCycle = true;
            }
        }
        if(!negtiveCycle) break;
    }
    return negtiveCycle;
}

// Dijkstra子過程
vector<int> Dijkstra(int n, int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n+1, INT_MAX);
    vector<bool> vis(n+1, false);

    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        auto node = pq.top();
        pq.pop();
        int u = node.second;
        if(vis[u]) continue;
        vis[u] = true;
        for(auto e : adj[u]) {
            int v = e.v, w = e.w;
            if(dist[u] < INT_MAX && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int n = 5;
    edges = {{1,2,3}, {3,2,4}, {1,3,8}, {2,4,1}, {2,5,7}, {1,5,-4}, {4,1,2}, {5,4,6}, {4,3,-5}};

    // 構建新圖 G'，新增節點 s，並將到各節點的權重設為0，即： w(s,v)=0 v in G.V
    int s = 0;
    vector<Edge> edges_new = edges;
    for(int v = 1; v <= n; ++v) {
        edges_new.push_back({s, v, 0});
    }
    // 執行 BellmanFord算法，計算s的單點源最短路徑
    bool hasCycle = BellmanFord(edges_new, n, s);
    if(hasCycle) cout << "the input graph contains a negative-weight cycle" << endl;

    // 重新賦予權重 w'(u,v) = w(u,v) + h(u) - h(v)
    for(auto &e : edges_new) {
        e.w = e.w + dist[e.u] - dist[e.v];
    }

    // 構建新圖G'的鄰接表，Dijkstra算法需要使用到
    adj.resize(n+1);
    for(auto const e : edges_new) {
        adj[e.u].push_back(e);
    }

    // 在新圖上以每個頂點為源點，執行Dijkstra算法，計算單點源最短路徑
    vector<vector<int>> dist_all(n+1, vector<int>(n+1, 0));
    for(int i = 1; i <= n; ++i) {
       auto d = Dijkstra(n, i);
       for(int j = 1; j <= n; ++j) {
           if(d[j] == INT_MAX) continue;
           dist_all[i][j] = d[j] + dist[j] - dist[i]; // 恢復權值
       }
    }
    return 0;
}
