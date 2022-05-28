#include <bits/stdc++.h>
#define N_INF    2e-16
#define ll long long

using namespace std;


void solve() {
       ll n, sum = 0, result = N_INF;
       vector<ll>arr;
       cin >> n;
       for (int i = 0; i < n; i++) {
              ll x;
              cin >> x;
              arr.push_back(x);
       }
       for (int i = 0; i < n; i++) {
              sum += arr[i];
              if (sum < arr[i]) {
                     sum = arr[i];
              }
              if (result < sum) {
                     result = sum;
              }
       }
       cout << result << endl;
}



int main() {
    
       solve();


}



// Complexity of the algorithm is O(n)//
