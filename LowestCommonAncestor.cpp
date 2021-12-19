#include <bits/stdc++.h>
#define mx 1000000
#define ll long long

using namespace std;

vector<int> graph[mx];
int ancestor[mx];
void dfs(ll vertex, ll parent = -1) {
       ancestor[vertex] = parent;
       for (int i = 0; i < graph[vertex].size(); i++) {
              int next = graph[vertex][i];
              if (next == parent) {
                     continue;
              }
              dfs(next, vertex);
       }


}
vector<ll>path(int v) {
       vector<ll>ans;
       while (v != -1) {
              ans.push_back(v);
              v = ancestor[v];
       }
       
       return ans;
}

void solve() {
       int  edge, source = 1, x, y, lowestCommonAncestor = -1;
       cin >>  edge ;
       for (int i = 0; i < edge; i++) {
              int v1, v2;
              cin >> v1 >> v2;
              graph[v1].push_back(v2);
              graph[v2].push_back(v1);
       }
       dfs(source);
       cin >> x >> y;
       vector<ll>path_x = path(x);
       vector<ll>path_y = path(y);
       ll min_lenth = min(path_x.size(), path_y.size());
       reverse(path_x.begin(), path_x.end());
       reverse(path_y.begin(), path_y.end());
       for (int i = 0; i < min_lenth; i++) {
              if (path_x[i] == path_y[i]) {
                     lowestCommonAncestor = path_x[i];
              }
              else {
                     break;
              }
       }
       cout << lowestCommonAncestor;




}



int main() {

       solve();

}
