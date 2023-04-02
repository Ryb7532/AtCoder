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
#define printYorN(f) cout << (f ? Yes : No) << endl


int N;
vector<int> A;
int res = (1<<30)-1;

void dfs(int d, int ll, int rr, int v) {
  if (d == -1 || ll + 1 == rr) {
    res = min(res, v);
    return;
  }
  int l = ll-1, r = rr;
  while (r-l>1) {
    int m = (r+l)/2;
    if (A[m]&(1<<d))
      r = m;
    else
      l = m;
  }
  if (r == ll || l == rr-1)
    dfs(d-1, ll, rr, v);
  else {
    dfs(d-1, ll, r, v+(1<<d));
    dfs(d-1, r, rr, v+(1<<d));
  }
}

int main() {
  cin >> N;
  A.resize(N);
  rep(i,N) {
    cin >> A[i];
  }
  sort(all(A));
  dfs(29,0,N,0);
  print(res);
  return 0;
}
