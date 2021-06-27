#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << a << endl;
#define all(v) v.begin(), v.end();

int main() {
  int N, a;
  string S;
  cin >> N >> a >> S;
  a--;
  int b[N], id = a, s = 1, c[N], n = S.size(), k = 0;
  rep(i, N) {
    cin >> b[i];
    b[i]--;
  }
  fill(c, c+N, -1);
  while (c[id] == -1) {
    c[id] = s;
    s++;
    id = b[id];
  }
  if (n<=6) {
    rep(i, n) {
      k *= 10;
      k += S[i]-'0';
    }
    if (k < c[id]) {
      id = a;
      while (c[id] != k) {
        id = b[id];
      }
      print(b[id]+1);
      return 0;
    }
  }
  k = 0;
  s -= c[id];
  rep(i, n) {
    k *= 10;
    k += S[i]-'0';
    k %= s;
  }
  k -= c[id];
  k = ((k%s)+s)%s;
  k += c[id];
  while (c[id] != k) {
    id = b[id];
  }
  print(b[id]+1);
  return 0;
}
