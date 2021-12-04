#include <bits/stdc++.h>
#define mx 1000000
using namespace std;
/***************************************************************************************/

vector<int> graph[mx];
bool vis[mx];
int dis[mx];
void dfs(int vertex) {
       vis[vertex] = true;
       for (int i = 0; i < graph[vertex].size(); i++) {
              int next = graph[vertex][i];
              if (!vis[next]) {     //if not visited //
                     dis[next] = dis[vertex] + 1;  //child distance is +1 more than parent //
                     dfs(next);
              }

       }
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
       dfs(source);

}

int main() {

       solve();

}
