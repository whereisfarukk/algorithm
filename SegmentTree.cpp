#include <bits/stdc++.h>
#define ll long long
#define bit_on __builtin_popcount
using namespace std;
/***************************************************************************************/

vector<ll>tree;
ll tree_traverse(ll pos, ll cur_low, ll cur_high, ll q_low, ll q_high) {

    if (cur_low >= q_low && cur_high <= q_high) {

        return tree[pos];
    }
    if (cur_high < q_low || cur_low > q_high) {
        return 0;
    }
    ll mid = (cur_low + cur_high) / 2;

    return tree_traverse(pos * 2, cur_low, mid, q_low, q_high) +
           tree_traverse(pos * 2 + 1, mid + 1, cur_high, q_low, q_high);

}
void solve() {
    ll n, q, i;
    cin >> n >> q;
    vector<ll>v;
    for (i = 0; i < n; i++) {
        ll x;
        cin >> x;
        v.push_back(x);
    }
    while (bit_on(n) != 1) {
        v.push_back(0);
        n++;
    }

    tree.resize(n * 2);

    for ( i = 0; i < n; i++) {
        tree[n + i] = v[i];
    }
    for ( i = n - 1; i >= 1; i--) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
    while (q--) {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        cout << tree_traverse(1, 0, n - 1   , x, y) << endl;
    }

}


int main() {
  
    solve();
    return 0;

}
