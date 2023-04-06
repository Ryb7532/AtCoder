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


struct point {
  ll p;
  int x;

  bool operator<(const point &a) {
    return p*a.x > a.p*x;
  }
};

int main() {
  int N;
  cin >> N;
  vector<string> S(N);
  rep(i,N) {
    cin >> S[i];
  }
  vector<point> P(N);
  ll res = 0;
  int totalx = 0;
  rep(i,N) {
    ll p = 0;
    int x = 0;
    int s = S[i].size();
    rrep(j,s) {
      if (S[i][j] == 'X') {
        res += p;
        x++;
      } else {
        p += S[i][j]-'0';
      }
    }
    P[i] = {p, x};
    totalx += x;
  }
  sort(all(P));
  rep(i,N) {
    totalx -= P[i].x;
    res += totalx * P[i].p;
  }
  print(res);
  return 0;
}
