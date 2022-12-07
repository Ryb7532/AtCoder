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

vec<int> days = {31,29,31,30,31,30,31,31,30,31,30,31};

int main() {
  int N;
  cin >> N;
  vec<bool> h(500,false);
  rep(i,N) {
    int m,d;
    char slash;
    cin >> m >> slash >> d;
    m--; d--;
    rep(j,m) {
      d += days[j];
    }
    h[d] = true;
  }
  int ans = 0,s = 0;
  rep(i,500) {
    if (h[i]) {
      if (i%7 == 0 || i%7 == 6) {
        s++;
      }
    } else {
      if (i%7 == 0 || i%7 == 6)
        h[i] = true;
      else if (s>0) {
        h[i] = true;
        s--;
      }
    }
  }
  h[366] = false;
  s = 0;
  rep(i,367) {
    if (h[i])
      s++;
    else {
      ans = max(ans,s);
      s = 0;
    }
  }
  print(ans);
  return 0;
}
