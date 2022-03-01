#include <bits/stdc++.h>
#define ll long long 
using namespace std;


bool visited[100];
vector<ll>graph[10000];
vector<ll>ans;
void dfs(int source) {
       visited[source] = true;
       for (int i = 0; i < graph[source].size(); i++) {
              ll child = graph[source][i];
              if (!visited[child]) {
                     dfs(child);
              }
       }
       ans.push_back(source);
}
void solve() {
       ll node , edge;
       cin >> node >> edge;
       for (int i = 0; i < edge; i++) {
              ll u, v;
              cin >> u >> v;
              graph[u].push_back(v);
       }
       for (int i = 1; i <= node; i++) {
              if (!visited[i]) {
                     dfs(i);
              }
       }
       reverse(ans.begin(), ans.end());
       for (int i = 0; i < ans.size(); i++) {
              cout << ans[i] << " ";
       }


}

int main() {

       solve();

}
