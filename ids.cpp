#include <bits/stdc++.h>
#define mx 1000000
using namespace std;

vector<int> graph[mx];
bool vis[mx];
int dis[mx];

bool dls(int vertex, int maxDepth) {
    vis[vertex] = true;
    if (maxDepth == 0) {
        return true;  // Return true if the depth limit is reached.
    }
    bool found = false;
    for (int i = 0; i < graph[vertex].size(); i++) {
        int next = graph[vertex][i];
        if (!vis[next]) {
            dis[next] = dis[vertex] + 1;
            found |= dls(next, maxDepth - 1);  // Decrement maxDepth for the child nodes.
        }
    }
    return found;
}

void solve() {
    int edge, source;
    cin >> edge;
    for (int i = 0; i < edge; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    cin >> source;
    dis[source] = 0;
    
    int maxDepth = 0;
    while (true) {
        memset(vis, false, sizeof(vis));  // Reset visited array for each iteration
        if (dls(source, maxDepth)) {
            // If dls returns true, a solution is found within maxDepth, break the loop.
            break;
        }
        maxDepth++;
    }
}

int main() {
    solve();
}

