#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,s,e) for (int i=s; i<(int)(e); i++)
#define repn(i,n) rep(i,0,n)
#define rrep(i,s,e) for (int i=s-1; i>=e; i--)
#define rrepn(i,n) rrep(i,n,0)
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
  vector<int> cntA(28,0), cntB(28,0);
  vector<vector<int>> remA(28, vector<int>(N)), remB(28, vector<int>(N));
  repn(i,N) {
    int a;
    cin >> a;
    repn(j,28) {
      if (a&(1<<j))
        cntA[j]++;
      remA[j][i] = a%(1<<(j+1));
    }
  }
  repn(i,N) {
    int b;
    cin >> b;
    repn(j,28) {
      if (b&(1<<j))
        cntB[j]++;
      remB[j][i] = b%(1<<(j+1));
    }
  }
  repn(j,28) {
    sort(all(remA[j]));
    sort(all(remB[j]));
  }
  int up = 0;
  int res = 0;
  repn(j,28) {
    int cnt = up + cntA[j]*(N-cntB[j]) + (N-cntA[j])*cntB[j];
    if (cnt%2)
      res += 1<<j;
    int idb = N;
    up = 0;
    repn(ida,N) {
      while (idb > 0 && remA[j][ida]+remB[j][idb-1] >= (1<<(j+1)))
        idb--;
      up += N-idb;
    }
  }
  if (up%2)
    res += 1<<28;
  print(res);
  return 0;
}
