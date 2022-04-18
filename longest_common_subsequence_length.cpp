#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e5;

vector<ll>v(N, 0);
ll lis(ll n) {
    vector<ll>lis_arr;
    lis_arr.push_back(v[0]);
    for (int i = 1; i < n; i++) {

        if (v[i] > lis_arr[lis_arr.size() - 1]) {
            lis_arr.push_back(v[i]);

        }
        else {

            auto it = lower_bound(lis_arr.begin(), lis_arr.end(), v[i]);
            int index = (it - lis_arr.begin());
            lis_arr[index] = v[i];
        }
    }

    return lis_arr.size();
}
void solve() {
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout<<lis(n);


}
int main() {

    solve();
    return 0;

}
