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
                ans += m[c];/*Here we are just adding same string palindrome pair number*/
               
               /*After making bitmask of c ,then we are searching for a string which can be make palindrome with c.Basically here we
               are searching every combination that can be palindrome with c.*/
                for (ll j = 0; j < 26; j++) {
                        ans += (m[c ^ (1 << j)]);
                }
                m[c]++;

        }
        cout << ans << endl;

return 0;
}
