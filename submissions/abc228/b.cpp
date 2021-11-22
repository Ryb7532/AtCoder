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
  int N, X;
  cin >> N >> X;
  vec<int> A(N);
  rep(i,N) {
    cin >> A[i];
  }
  set<int> known;
  while (known.find(X) == known.end()) {
    known.insert(X);
    X = A[X-1];
  }
  print(known.size());
  return 0;
}
