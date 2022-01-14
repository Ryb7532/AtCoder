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
  int N,Q;
  cin >> N;
  vector<int> R(N), C(N);
  rep(i,N) {
    cin >> R[i];
  }
  rep(i,N) {
    cin >> C[i];
  }
  cin >> Q;
  rep(_,Q) {
    int r,c;
    cin >> r >> c;
    r--; c--;
    if (R[r] + C[c] > N) {
      cout << '#';
    } else {
      cout << '.';
    }
  }
  cout << endl;
  return 0;
}
