#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl


int main() {
  int N,K;
  cin >> N >> K;
  vector<ll> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  ll res;
  set<ll> candidate;
  candidate.insert(0);
  K++;
  while (K > 0) {
    res = *candidate.begin();
    candidate.erase(res);
    K--;
    rep(i,N) {
      candidate.insert(res+A[i]);
    }
  }
  print(res);
  return 0;
}
