#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int H,W,X,Y;
  cin >> H >> W >> X >> Y;
  X--; Y--;
  vec<string> S(H);
  rep(i,H)
    cin >> S[i];
  int res = 1;
  int i=X+1;
  while (i<H && S[i][Y]=='.') {
    res++;
    i++;
  }
  i=X-1;
  while (i>=0 && S[i][Y]=='.') {
    res++;
    i--;
  }
  i=Y+1;
  while (i<W && S[X][i]=='.') {
    res++;
    i++;
  }
  i=Y-1;
  while (i>=0 && S[X][i]=='.') {
    res++;
    i--;
  }
  print(res);
  return 0;
}
