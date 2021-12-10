#include <bits/stdc++.h>
#define ll long long

using namespace std;


void solve() {
 int  t;
    cin >> t;
    while (t--) {
        deque<int>dq;
        vector<int > ans;
        vector<int>v;
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && dq.back() < v[i]) {
                dq.pop_back();
            }
            dq.push_back(v[i]);
        }
        ans.push_back(dq.front());
        for (int i = k; i < n; i++) {
            if (dq.front() == v[i - k]) {
                dq.pop_front();
            }
            while (!dq.empty() && dq.back() < v[i]) {
                dq.pop_back();
            }
            dq.push_back(v[i]);
            ans.push_back(dq.front());
        }
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;

    }

}



int main() {
    solve();
    return 0;

}
