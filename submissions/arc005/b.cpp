#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << a << endl
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


int main() {
  int x,y;
  string W;
  cin >> x >> y >> W;
  x--; y--;
  string c[9];
  rep(i,9) cin >> c[i];
  int u=0,r=0;
  if (W.back() == 'U') {
    u = -1;
    W.pop_back();
  } else if (W.back() == 'D') {
    u = 1;
    W.pop_back();
  }
  if (!W.empty()) {
    if (W.back() == 'R')
      r = 1;
    else
      r = -1;
  }
  rep(i,4) {
    cout << c[abs(8-abs(y-8))][abs(8-abs(x-8))];
    y += u;
    x += r;
  }
  cout << endl;
  return 0;
}
