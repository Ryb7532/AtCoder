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
  int N,M;
  cin >> N >> M;
  vector<string> S(N),T(M);
  vector<bool> res(N,false);
  rep(i,N) {
    cin >> S[i];
  }
  rep(i,M) {
    cin >> T[i];
  }
  int j = 0;
  rep(i,M) {
    while (j<N && S[j] != T[i]) {
      j++;
    }
    res[j] = true;
  }
  rep(i,N) {
    print((res[i] ? Yes : No));
  }
  return 0;
}
