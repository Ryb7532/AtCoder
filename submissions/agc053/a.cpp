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
  string S;
  cin >> N >> S;
  vector<int> A(N+1);
  rep(i,N+1) {
    cin >> A[i];
  }
  int k = 1e5;
  rep(i,N) {
    k = min(k, abs(A[i]-A[i+1]));
  }
  print(k);
  rep(i,k) {
    rep(j,N+1) {
      cout << (A[j]+i)/k << ' ';
    }
    cout << endl;
  }
  return 0;
}
