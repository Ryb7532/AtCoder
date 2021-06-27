#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << a << endl;
#define all(v) v.begin(), v.end();

int main() {
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;
  int a[N], b[M];
  rep(i, N)
    cin >> a[i];
  rep(i, M)
    cin >> b[i];
  int ans = 0, ia = 0, ib = 0, t = 0;
  while (1) {
    while (ia != N && a[ia]<t)
      ia++;
    if (ia == N)
      break;
    t = a[ia]+X;
    while (ib != M && b[ib]<t)
      ib++;
    if (ib == M)
      break;
    ans++;
    t = b[ib]+Y;
  }
  print(ans);
  return 0;
}
