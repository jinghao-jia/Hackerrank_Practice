/* Refer to the BFS Graph Searching algorithm in CSE100 Slides */
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Graph {
  vector<vector<int>> adj;
  vector<int> dists;
public:
  Graph(int n);

  inline void add_edge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> & shortest_reach(int start);
};

Graph::Graph(int n) {
  adj = vector<vector<int>>(n, vector<int>());
  dists = vector<int>(n, -1);
}

vector<int> & Graph::shortest_reach(int start) {
  int next, neighbor;
  queue<int> explore;
  dists[start] = 0;
  explore.push(start);

  while(!explore.empty()) {
    next = explore.front();
    explore.pop();
    for(auto it = adj[next].begin(); it != adj[next].end(); ++it) {
      neighbor = *it;
      if(dists[neighbor] == -1) {
        dists[neighbor] = dists[next] + 6;
        explore.push(neighbor);
      }
    }
  }
  return dists;
}

int main() {
  int queries;
  cin >> queries;

  for (int t = 0; t < queries; t++) {

    int n, m;
    cin >> n;
    // Create a graph of size n where each edge weight is 6:
    Graph graph(n);
    cin >> m;
    // read and set edges
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      // add each edge to the graph
      graph.add_edge(u, v);
    }
    int startId;
    cin >> startId;
    startId--;
    // Find shortest reach from node s
    vector<int> distances = graph.shortest_reach(startId);

    for (int i = 0; i < distances.size(); i++) {
      if (i != startId) {
        cout << distances[i] << " ";
      }
    }
    cout << endl;
  }

  return 0;
}
