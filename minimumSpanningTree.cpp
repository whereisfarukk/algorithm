#include <bits/stdc++.h>
using namespace std;

/************************************************************************************************/
int const N = 1e5 + 10;
int parent[N];
int sz[N];
bool cmp(pair<int, pair<int, int>>a, pair<int, pair<int, int>>b) {
       // if(a.second.second!=b.second.second){
       return a.second.second < b.second.second;


}
void make(int v) {
       parent[v] = v;
       sz[v] = 1;
}
int find(int v) {
       if (parent[v] == v) {
              return v;
       }
       return parent[v] = find(parent[v]);

}
void Union(int a, int b) {
       int parentOfa = find(a);
       int parentOfb = find(b);
       if (parentOfa != parentOfb) {
              if (sz[a] < sz[b]) {
                     swap(parentOfa, parentOfb);
              }
              parent[parentOfb] = parentOfa;
              sz[parentOfa] += sz[parentOfb];
       }

}
void solve() {
       int nodes, edges;
       vector<pair<int, pair<int, int>>>graph;
       cin >> nodes >> edges;
       for (int i = 0; i < edges; i++) {
              int u, v, w;
              cin >> u >> v >> w;
              graph.push_back({u, {v, w}});
       }
       sort(graph.begin(), graph.end(), cmp);
       for (int i = 1; i <= nodes; i++) {
              make(i);
       }
       int total=0;
       for (auto it : graph) {
              int u, v;
              u = it.first, v = it.second.first;
              if (find(u) == find(v)) {

                     continue;
              }
              Union(u, v);
              total+=it.second.second;
              cout << it.first << " " << it.second.first << " " << it.second.second << endl;
       }

}

int main() {

       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       solve();

}
