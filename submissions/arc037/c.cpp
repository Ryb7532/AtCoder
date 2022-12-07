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
  int N,K;
  cin >> N >> K;
  vector<ll> a(N), b(N);
  rep(i,N) cin >> a[i];
  rep(i,N) cin >> b[i];
  sort(all(a)); sort(all(b));
  ll l=0,r=a[N-1]*b[N-1];
  while (r-l>1) {
    ll mid = (r+l)/2;
    int cnt = 0;
    rep(i,N) {
      auto it = lower_bound(all(b), mid/a[i]+1);
      cnt += it-b.begin();
    }
    if (cnt>=K)
      r = mid;
    else
      l = mid;
  }
  print(r);
  return 0;
}
