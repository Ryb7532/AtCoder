#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0; i<n; i++)
#define reps(i,s,n) for (int i=s, i<n; i++)
#define rep1(i,n) for (int i=1; i<=n; i++)
#define print(a) cout << a << endl;

int main() {
  string S;
  cin >> S;
  int n = S.size(), ans = 0;
  ll v = 0;
  rep(i, n) {
    if (S[i] == '+') {
      if (v == 0)
        ans++;
      v = 0;
    } else if (S[i] == '0')
      v++;
  }
  if (v == 0)
    ans++;
  print(ans);
  return 0;
}
