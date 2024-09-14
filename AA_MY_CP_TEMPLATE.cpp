#include <bits/stdc++.h>
#define N_INF    1e5+10
#define P_INF    2e16
#define PI     3.14159265358979323846
#define Dpos(n)  fixed<<setprecision(n)
#define M    1000000007;
#define REP(i, n)  for (int i = 0; (i) < (int)(n); ++ (i))
#define REP2(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define rev(v)    reverse(v.begin(),v.end())
#define countv(v,a)   count(v.begin(),v.end(),a)
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define lld long  double
#define bit_on __builtin_popcount
#define lb lower_bound
#define ub upper_bound
#define grtsrt(v)  sort(v.begin(),v.end(),greater<int>())
#define lcm(x,y) (x/__gcd(x,y))*y
const int dx[4] = { -1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
using namespace std;

/************************************************************************************************/

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.f); cerr << ","; _print(p.s); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <size_t R, size_t C> void _print(ll (&arr)[R][C]) { cerr << "[ "; for (size_t i = 0; i < R; ++i) { cerr << "[ "; for (size_t j = 0; j < C; ++j) { _print(arr[i][j]); cerr << " "; } cerr << "] "; } cerr << "]"; }


/************************************************************************************************/


void solve() {

}

int main() {
#ifndef ONLINE_JUDGE
       freopen("infutf.txt", "r", stdin);
       freopen("outputf.txt", "w", stdout);
#endif
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       solve();

}
