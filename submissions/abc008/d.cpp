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

struct box {
  int l, r, b, t;
  bool operator<(const box &a) const {
    if (this->l != a.l)
      return this->l < a.l;
    if (this->r != a.r)
      return this->r < a.r;
    if (this->b != a.b)
      return this->b < a.b;
    return this->t < a.t;
  }
};
map<box, ll> memo;
int N;
vector<int> X, Y;

ll f(box b) {
  if (memo.find(b) != memo.end())
    return memo[b];
  if (b.l > b.r || b.b > b.t)
    return 0;
  ll res = 0;
  rep(i,N) {
    if (X[i] < b.l || X[i] > b.r || Y[i] < b.b || Y[i] > b.t)
      continue;
    res = max(res, f({b.l, X[i]-1, b.b, Y[i]-1}) + f({X[i]+1, b.r, b.b, Y[i]-1}) + f({b.l, X[i]-1, Y[i]+1, b.t}) + f({X[i]+1, b.r, Y[i]+1, b.t}) + b.r-b.l+b.t-b.b+1);
  }
  memo[b] = res;
  return res;
}

int main() {
  int H,W;
  cin >> W >> H >> N;
  X.resize(N);
  Y.resize(N);
  rep(i,N) {
    cin >> X[i] >> Y[i];
  }
  print(f({1,W,1,H}));
  return 0;
}
