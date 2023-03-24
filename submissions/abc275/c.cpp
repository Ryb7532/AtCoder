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
  vector<string> S(9);
  rep(i,9) {
    cin >> S[i];
  }
  int res = 0;
  rep(i,9) {
    rep(j,9) {
      rep(k,9) {
        rep(l,9) {
          if (i==k && j == l)
            continue;
          int dy = k-i;
          int dx = l-j;
          if ((dy+10)%2 != (dx+10)%2)
            continue;
          int w = (dx+dy)/2;
          int h = (dx-dy)/2;
          if (i+w<0 || i+w>=9 || j+h<0 || j+h>=9 || i-h<0 || i-h>=9 || j+w<0 || j+w>=9)
            continue;
          if (S[i][j] == '#' && S[k][l] == '#' && S[i+w][j+h] == '#' && S[i-h][j+w] == '#')
            res++;
        }
      }
    }
  }
  print(res/4);
  return 0;
}
