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
  string s;
  cin >> s;
  int n = s.size();
  if (s[n-1] == '1' || s[0] == '0') {
    print(-1);
    return 0;
  }
  rep(i,n/2) {
    if (s[i] != s[n-i-2]) {
      print(-1);
      return 0;
    }
  }
  int par=1,node=2;
  rep(i,n/2) {
    if (s[i] == '1') {
      print(par << ' ' << node);
      par = node;
      node++;
    } else {
      print(par << ' ' << node);
      node++;
    }
  }
  while (node <= n) {
    print(par << ' ' << node);
    node++;
  }
  return 0;
}
