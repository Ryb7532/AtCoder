#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
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
  vector<ll> ans;
  for (ll i=N-153;i<N;i++) {
    ll x=i,f=0;
    while (x>0) {
      f += x%10;
      x /= 10;
    }
    if (N == i+f) {
      ans.push_back(i);
    }
  }
  if (ans.empty()) {
    print(0);
  } else {
    int n = ans.size();
    print(n);
    rep(i,n) {
      print(ans[i]);
    }
  }
  return 0;
}
