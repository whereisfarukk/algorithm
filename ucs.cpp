#include <bits/stdc++.h>
#define mx 1000000
using namespace std;

typedef pair<int, int> pii;  // Define a pair for cost and node

vector<pii> graph[mx];  // Each element is a pair (cost, destination node)
int dis[mx];

void ucs(int source) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;  // Min-heap priority queue
    pq.push({0, source});  // Starting from the source node with cost 0
    
    while (!pq.empty()) {
        pii current = pq.top();
        pq.pop();
        
        int cost = current.first;
        int node = current.second;
        
        if (dis[node] < cost) {
            continue;  // Skip if a shorter path to this node has already been found
        }
        
        for (pii neighbor : graph[node]) {
            int nextNode = neighbor.second;
            int edgeCost = neighbor.first;
            
            if (dis[nextNode] > dis[node] + edgeCost) {
                dis[nextNode] = dis[node] + edgeCost;
                pq.push({dis[nextNode], nextNode});
            }
        }
    }
}

void solve() {
    int nodes, edges, source;
    cin >> nodes >> edges;
    
    for (int i = 0; i < edges; i++) {
        int v1, v2, cost;
        cin >> v1 >> v2 >> cost;
        graph[v1].push_back({cost, v2});
        graph[v2].push_back({cost, v1});  // Assuming undirected graph
    }
    
    cin >> source;
    memset(dis, 0x3f, sizeof(dis));  // Initialize distances to a large value (similar to INT_MAX)
    dis[source] = 0;  // Distance to the source is 0
    
    ucs(source);
    
    // Print the shortest distances from the source to all nodes
    for (int i = 1; i <= nodes; i++) {
        cout << "Shortest distance from " << source << " to " << i << " is " << dis[i] << endl;
    }
}

int main() {
    solve();
}

