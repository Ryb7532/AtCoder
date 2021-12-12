#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int N,Q;
  cin >> N >> Q;
  vector<int> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  sort(all(A));
  rep(_,Q) {
    int x;
    cin >> x;
    auto it = lower_bound(all(A), x);
    print(distance(it, A.end()));
  }
  return 0;
}
