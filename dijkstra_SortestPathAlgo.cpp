#include <bits/stdc++.h>
#define P_INF    2e16
#define ll long long
using namespace std;
/***************************************************************************************/

vector<pair<ll, ll>>graph[10000000];
bool visited[100000];
void dijkstra(vector<ll>&distance, ll source) {
       priority_queue<pair<ll , ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>> >p;
       p.push({0, source});
       distance[source] = 0;
       while (!p.empty()) {
              pair<ll, ll>current_node = p.top();
              p.pop();
              ll vertex = current_node.second;
              if (visited[vertex]) {
                     continue;
              }
              else {
                     visited[vertex] = true; /* we declare visited in bfs inside for loop.But
                     in dijkstra we declare it outside of for loop becaue a node can be visited
                     multiple time as its distance can be reduce*/

                     for (int i = 0; i < graph[vertex].size(); i++) {
                            ll child = graph[vertex][i].first;
                            ll weight = graph[vertex][i].second;
                            if (distance[vertex] + weight < distance[child]) {
                                   distance[child] = distance[vertex] + weight;
                                   p.push({distance[child], child});
                            }

                     }
              }

       }
       for (int i = 0; i < distance.size(); i++) {
              cout << i << " " << distance[i] << endl;
       }

}
void solve() {
       ll node, edge;
       cin >> node >> edge;
       vector<ll>distance(node, P_INF);

       for (int i = 0; i < edge; i++) {
              ll u, v, wt;
              cin >> u >> v >> wt;
              graph[u].push_back({v, wt});
       }
       dijkstra(distance, 0);

}



int main() {
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       solve();

}
