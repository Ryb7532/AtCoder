#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int N;
  ll H;
  cin >> N >> H;
  vector<ll> A(N), B(N);
  rep(i,N) {
    cin >> A[i] >> B[i];
  }
  sort(rall(A));
  sort(rall(B));
  ll res = 0;
  rep(i,N) {
    if (B[i]<A[0] || H<=0)
      break;
    H -= B[i];
    res++;
  }
  H = max((ll)0,H);
  res += (H+A[0]-1)/A[0];
  print(res);
  return 0;
}
