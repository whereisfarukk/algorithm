#include <bits/stdc++.h>
#define ll long long
using namespace std;
map<ll, ll>m;

int main()
{
       ll n;
        cin >> n;
  //Input how many pair will be given*/
        ll sum = 0, ans = 0, flag = 0;
        for (ll i = 0; i < n; i++) {
                string str;
                cin >> str;
                ll c = 0;
          /*After taking string input then make a bitmsk for that string*/
                for (ll  j = 0; j < str.size(); j++) {
                        c ^= (1 << (str[j] - 'a'));
                }
                ans += m[c];
          /*if the string size is even and palindrome that means the bitmask of that string is 0.Then it can be make pair with any 
          string which is odd and palindrome.A odd and palindrome string bitmask is 1 and we sum the total number of odd palindrome 
          number of string.*/
                for (ll j = 0; j < 26; j++) {
                        ans += (m[c ^ (1 << j)]);
                }
                m[c]++;

        }
        cout << ans << endl;

return 0;
}
