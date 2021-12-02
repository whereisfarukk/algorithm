#include <bits/stdc++.h>
using namespace std;
/***************************************************************************************/

void permutation(string str, int lb, int ub) {
    if (ub == lb) {
        cout << str << endl;
        return;
    }
    for (int i = lb; i <= ub; i++) {
        swap(str[lb], str[i]);
        permutation(str, lb + 1, ub);
        swap(str[lb], str[i]);

    }
}
void solve() {
    string str;
    cin >> str;
    int lb = 0, ub = str.size() - 1;
    permutation(str, lb, ub);
}

int main() {
    solve();
    return 0;

}
