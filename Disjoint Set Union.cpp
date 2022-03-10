#include <bits/stdc++.h>
using namespace std;

/************************************************************************************************/
int const N = 1e5;
int parent[N];
int size[N];
void make(int v) {
       parent[v] = v;
       size[v] = 1;
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
              if (size[a] < size[b]) {
                     swap(parentOfa, parentOfb);
              }
              parent[parentOfb] = parentOfa;
              size[parentOfa] += size[parentOfb];
       }

}
void solve() {
       int n, k;
       cin >> n >> k;
       for (int i = 1; i <= n; i++) {
              make(i);
       }
       while (k--) {
              int u, v;
              cin >> u >> v;
              Union(u, v);
       }
       int cont = 0;
       for (int i = 1; i <= n; i++) {
              if (find(i) == i) {
                     cont++;
              }
              // cout<<"parent of "<<i<<" is :"<<parent[i]<<endl;
       }
       cout << cont << endl;

}

int main() {
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       solve();

}
