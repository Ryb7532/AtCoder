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
  cin >> N;
  vector<int> A(N);
  rep(i,N)
    cin >> A[i];
  int Q;
  cin >> Q;
  rep(_,Q) {
    int q,k;
    cin >> q >> k;
    k--;
    if (q == 1) {
      int x;
      cin >> x;
      A[k] = x;
    } else {
      print(A[k]);
    }
  }
  return 0;
}
