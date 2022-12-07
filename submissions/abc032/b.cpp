#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i=0; i<n; i++)
#define reps(i,s,n) for (int i=s; i<n; i++)
#define rep1(i,n) for (int i=1; i<=n; i++)
#define print(a) cout << a << endl;

int main() {
  string s;
  int k, n, ans = 0;
  bool c;
  cin >> s >> k;
  n = s.size();
  if (n-k<0) {
    print(0);
    return 0;
  }
  rep(i, n-k+1) {
    c = true;
    reps(j, i+1, n-k+1) {
      if (s.substr(i, k).compare(s.substr(j, k)) == 0)
        c = false;
    }
    if (c)
      ans++;
  }
  print(ans);
  return 0;
}
