#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()

int main() {
  string S;
  int N, l, r;
  cin >> S >> N;
  rep(i, N) {
    cin >> l >> r;
    l--;
    string m = S.substr(l, r-l);
    reverse(all(m));
    rep(j, r-l) {
      S[j+l] = m[j];
    }
  }
  print(S);
  return 0;
}
