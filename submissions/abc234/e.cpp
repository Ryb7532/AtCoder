#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
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
  string X;
  cin >> X;
  int N = X.size();
  if (N<=2) {
    print(X);
    return 0;
  }
  vector<int> res(N);
  res[0] = X[0]-'0';
  res[1] = X[1]-'0';
  while(true) {
    int d = res[1]-res[0];
    bool f0 = true, f1 = true;
    for (int i=2; i<N; i++) {
      res[i] = res[i-1]+d;
      if (res[i]<0 || res[i]>9)
        f0 = false;
    }
    rep(i,N) {
      if (res[i]>X[i]-'0')
        break;
      else if (res[i]<X[i]-'0') {
        f1 = false;
        break;
      }
    }
    if (f0&&f1) {
      break;
    }
    res[1]++;
    if (res[1]>9) {
      res[1] = 0;
      res[0]++;
    }
  }
  rep(i,N) {
    cout << res[i];
  }
  cout << endl;
  return 0;
}
