#include <iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // adjacency list: {neighbor, weight}
    vector<pair<int, int>> adj[n + 1];

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        // undirected graph
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    // distance array
    vector<long long> dist(n + 1, 1e18);

    // parent array for path
    vector<int> parent(n + 1);

    // initialize parent
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    // min heap {distance, node}
    priority_queue<pair<long long, int>,
                   vector<pair<long long, int>>,
                   greater<pair<long long, int>>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    // DIJKSTRA
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();

        long long d = it.first;
        int node = it.second;

        for (auto edge : adj[node]) {
            int adjNode = edge.first;
            int weight = edge.second;

            if (d + weight < dist[adjNode]) {
                dist[adjNode] = d + weight;
                pq.push({dist[adjNode], adjNode});

                // store parent
                parent[adjNode] = node;
            }
        }
    }

    // if no path exists
    if (dist[n] == 1e18) {
        cout << -1 << endl;
        return 0;
    }

    // reconstruct path
    vector<int> path;
    int node = n;

    while (parent[node] != node) {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);

    reverse(path.begin(), path.end());

    // print path
    for (int x : path) {
        cout << x << " ";
    }

    return 0;
}