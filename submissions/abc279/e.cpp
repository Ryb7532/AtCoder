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


int main() {
  int N,M;
  cin >> N >> M;
  vector<int> B(N);
  rep(i,N) {
    B[i] = i;
  }
  vector<int> C(M, 0);
  rep(i,M) {
    int a;
    cin >> a;
    if (B[a] == 0)
      C[i] = B[a-1];
    if (B[a-1] == 0)
      C[i] = B[a];
    swap(B[a], B[a-1]);
  }
  vector<int> id(N);
  rep(i,N) {
    id[B[i]] = i+1;
  }
  rep(i,M) {
    print(id[C[i]]);
  }
  return 0;
}
