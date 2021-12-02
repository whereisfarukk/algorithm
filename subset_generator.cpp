#include <bits/stdc++.h>
#define ll long long

using namespace std;
/***************************************************************************************/

void generate(vector<ll>&subset, ll i, vector<ll>&num)
{
        if (i == num.size()) {
                for (int j = 0; j < subset.size(); j++) {
                        cout << subset[j];
                }
                cout << endl;
                return ;
        }

        generate(subset, i + 1, num);
        subset.push_back(num[i]);
        generate(subset, i + 1, num);
        subset.pop_back();

}
void solve() {
        vector<ll>num({1, 2, 3});
        vector<ll>empty;
        generate(empty, 0, num);
}

int main() {

        solve();
        return 0;
}
