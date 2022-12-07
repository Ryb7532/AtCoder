#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())


int main() {
  int N, K, t, d;
  cin >> N >> K;
  vector<pii> s, dbl;
  vector<int> cnt(N, 0);
  ll ans = 0, sum = 0, k = 0;
  rep(i,N) {
    cin >> t >> d;
    t--;
    s.push_back(make_pair(d, t));
  }
  sort(all(s));
  rep(i,K) {
    pii p = s.back();
    s.pop_back();
    if (cnt[p.second] != 0)
      dbl.push_back(p);
    else {
      k++;
      cnt[p.second]++;
    }
    sum += p.first;
  }
  rsort(dbl);
  ans = sum + k*k;
  while (!dbl.empty() && !s.empty()) {
    pii p = s.back();
    s.pop_back();
    if (cnt[p.second] != 0)
      continue;
    k++;
    cnt[p.second]++;
    sum += p.first;
    p = dbl.back();
    dbl.pop_back();
    sum -= p.first;
    ans = max(ans, sum+k*k);
  }
  print(ans);
  return 0;
}
