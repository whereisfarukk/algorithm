#include <bits/stdc++.h>
#define mx 1000000
using namespace std;

vector<int> graph[mx];
bool vis[mx];
int subTreeSum[mx];
void dfs(int vertex, int parent) {
     
       for (int i = 0; i < graph[vertex].size(); i++) {
              int next = graph[vertex][i];
              if(next==parent){
                     continue;
              }
              dfs(next,vertex);
              subTreeSum[vertex]+=subTreeSum[next];
       }
       subTreeSum[vertex]+=vertex;

}

void solve() {
       int  node,edge, source = 1;
       cin >> node >>  edge ;
       for (int i = 0; i < edge; i++) {
              int v1, v2;
              cin >> v1 >> v2;
              graph[v1].push_back(v2);
              graph[v2].push_back(v1);
       }
       dfs(source,0);
       for(int i=1;i<=node;i++){
              cout<<subTreeSum[i]<<endl;
       }

}



int main() {

       solve();

}
