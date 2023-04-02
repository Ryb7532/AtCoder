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
  int N;
  ll X;
  cin >> N >> X;
  vector<ll> A(N);
  set<ll> A_;
  rep(i,N) {
    cin >> A[i];
    A_.insert(A[i]);
  }
  bool flag = false;
  rep(i,N) {
    if (A_.find(A[i]-X) != A_.end())
      flag = true;
  }
  printyesno(flag);
  return 0;
}
