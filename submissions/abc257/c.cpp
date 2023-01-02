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
  int N;
  string S;
  cin >> N >> S;
  vector<pair<int,bool>> W(N);
  int M = 0;
  rep(i,N) {
    int w;
    cin >> w;
    bool f = S[i] == '1';
    if (f)
      M++;
    W[i] = {w, f};
  }
  sort(all(W));
  int res = M;
  int i = 0;
  int m = 0;
  while (i < N) {
    int w = W[i].first;
    while (i < N && W[i].first == w) {
      if (W[i].second)
        M--;
      else
        m++;
      i++;
    }
    res = max(res, M+m);
  }
  print(res);
  return 0;
}
