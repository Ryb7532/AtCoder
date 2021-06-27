#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())


int main() {
  ll N;
  cin >> N;
  ll ans;
  ans = N*(N+1)*(N+2)/6;
  rep(i,N-1) {
    ll u,v;
    cin >> u >> v;
    if (u>v)
      swap(u,v);
    ans -= u*(N-v+1);
  }
  print(ans);
  return 0;
}
