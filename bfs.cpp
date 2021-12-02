#include <bits/stdc++.h>
#define ll long long
#define mx 10000
using namespace std;
/***************************************************************************************/
vector<int > graph[mx];
void bfs(bool vis[], int dis[], int source) {
       queue<int >q;
       int cont = 0;
       vis[source] = 1;
       dis[source] = 0;
       q.push(source);
       while (!q.empty()) {
              int node = q.front();
              q.pop();
              for (int i = 0; i < graph[node].size(); i++) {
                     int next = graph[node][i];
                     if (!vis[next]) {
                            q.push(next);
                            vis[next] = 1;
                            dis[next] = dis[node] + 1;
                     }
              }
       }

}

void solve() {
       int edge;
       cin >> edge;
       if (edge == 0) {
              cout << "No answer" << endl;
       }
       else {

              for (int i = 0; i < edge; i++) {
                     int x, y;
                     cin >> x >> y;
                     graph[x].push_back(y);
                     graph[y].push_back(x);
              }

              bool vis[mx] = {false};
              int dis[mx];
              int source;
              cin >> source ;

              bfs(vis, dis, source);

       }

}



int main() {

       solve();

}
