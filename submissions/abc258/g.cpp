#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define rrep(i,n) for (int i=(int)(n)-1; i>=0; i--)
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
  cin >> N;
  vector<bitset<3000>> A(N);
  rep(i,N) {
    string s;
    cin >> s;
    A[i] = bitset<3000>(s);
  }
  ll res = 0;
  rep(i,N) {
    rep(j,N) {
      if (A[i][N-1-j]) {
        res += (A[i] & A[j]).count();
      }
    }
  }
  print(res/6);
  return 0;
}
