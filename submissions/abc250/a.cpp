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
  int H,W,R,C;
  cin >> H >> W >> R >> C;
  int res = 4;
  if (H == 1)
    res--;
  if (W == 1)
    res--;
  if (R == H || R == 1)
    res--;
  if (C == W || C == 1)
    res--;
  print(res);
  return 0;
}
