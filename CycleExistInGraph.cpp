
#include <bits/stdc++.h>
#define mx 1000000
using namespace std;
/***************************************************************************************/

vector<int> graph[mx];
bool vis[mx];
bool dfs(int vertex, int parent) {
       vis[vertex] = true;
       bool isLoopExist = false;
       for (int i = 0; i < graph[vertex].size(); i++) {
              int next = graph[vertex][i];
              if (vis[next] && next != parent) {
                     return true;
              }
              else if (!vis[next]) {
                     isLoopExist |= dfs(next, vertex);
              }

       }
       return  isLoopExist;
}

void solve() {
       int nodes, edge, source;
       cin >> nodes >> edge ;
       for (int i = 0; i < edge; i++) {
              int v1, v2;
              cin >> v1 >> v2;
              graph[v1].push_back(v2);
              graph[v2].push_back(v1);
       }
       bool isLoopExist = false;
       for (int i = 0; i < nodes; i++) {
              if (vis[i]) {
                     continue;
              }
              else {
                     if (isLoopExist)
                     {
                            break;
                     }
                     isLoopExist |= dfs(i, 0);
              }
       }
       cout << isLoopExist;


}



int main() {
    
       solve();

}
