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
#define YES "YES"
#define No "No"
#define NO "NO"
#define printYorN(f) cout << (f ? Yes : No) << endl


int main() {
  int M = 108;
  vector<int> P = {4,9,5,7,11,13,17,19,23};
  int L = P.size();
  int id = 1;
  print(M);
  rep(i,L) {
    rep(j,P[i]) {
      cout << id + (P[i]+j+1)%P[i] << " ";
    }
    id += P[i];
  }
  cout << endl;
  id = 1;
  ll m = 1;
  ll res = 1;
  rep(i,L) {
    int B,B_;
    cin >> B;
    B -= id;
    rep(_,P[i]-1) {
      cin >> B_;
    }
    while (res%P[i] != B) {
      res += m;
    }
    m *= P[i];
    id += P[i];
  }
  print(res);
  return 0;
}
