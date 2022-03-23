#include <bits/stdc++.h>
#define ll long long
#define mx 1000010
using namespace std;
/***************************************************************************************/

bool visited[mx];
ll dis[mx];
ll path[mx];
void dijkstra(vector<pair<ll, ll>> graph[], ll source, ll destination)
{
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> p;
        p.push({ 0, source });
        dis[source] = 0;
        while (!p.empty())
        {
                pair<ll, ll> current_node = p.top();
                p.pop();
                ll vertex = current_node.second;
                if (visited[vertex])
                {
                        continue;
                }
                else
                {
                        visited[vertex] = true;
                        ll sz = graph[vertex].size();
                        for (ll i = 0; i < sz; i++)
                        {
                                ll child = graph[vertex][i].first;
                                ll weight = graph[vertex][i].second;
                                if (dis[vertex] + weight < dis[child])
                                {
                                        dis[child] = dis[vertex] + weight;
                                        p.push({ dis[child], child });
                                        path[child] = vertex;
                                }
                        }
                }
        }
        for (int i = 1; i <= destination; i++) {
                cout<<"sortest distance of node "<<i<<" is :"<<dis[i]<<endl;
                cout << "sortest path is :";
                vector<ll>ans;
                ans.push_back(i);
                ll temp = i;
                while (path[temp] != -1)
                {
                        ans.push_back(path[temp]);
                        temp = path[temp];
                }
                reverse(ans.begin(), ans.end());
                for (ll i = 0; i < ans.size(); i++) {
                        cout << ans[i] << " ";
                }
                cout<<endl<<endl;
        }
}
void solve()
{
        vector<ll>ans;
        ll numberOfTown, numberOfRoad;
        cin >> numberOfTown >> numberOfRoad;
        vector<pair<ll, ll>> graph[numberOfTown + 10];
        for (ll i = 0; i <= numberOfTown; i++)
        {
                dis[i] = 1e16;
                visited[i] = false;
                path[i] = -1;
        }
        for (ll i = 0; i < numberOfRoad; i++)
        {
                ll u, v, wt;
                cin >> u >> v >> wt;
                graph[u].push_back({ v, wt });
                graph[v].push_back({ u, wt });
        }
        dijkstra(graph, 1, numberOfTown);

}

int main()
{
        solve();
        return 0;
}
