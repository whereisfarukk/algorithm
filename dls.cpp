#include <bits/stdc++.h>

#define mx 1000000
using namespace std;

vector < int > graph[mx];
bool vis[mx];
int dis[mx];

void dls(int vertex, int depth, int maxDepth) {
  vis[vertex] = true;
  if (depth > maxDepth) {
    return; // Return if depth exceeds the maximum depth limit.
  }
  for (int i = 0; i < graph[vertex].size(); i++) {
    int next = graph[vertex][i];
    if (!vis[next]) {
      dis[next] = dis[vertex] + 1;
      dls(next, depth + 1, maxDepth); // Increment depth for the child nodes.
    }
  }
}

void solve() {
  int edge, source, maxDepth;
  cin >> edge;
  for (int i = 0; i < edge; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    graph[v1].push_back(v2);
    graph[v2].push_back(v1);
  }
  cin >> source >> maxDepth;
  dis[source] = 0;
  dls(source, 0, maxDepth); // Start the DLS from the source node with maxDepth limit.
}

int main() {
  solve();
}
