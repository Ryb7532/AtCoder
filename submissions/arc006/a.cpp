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
  vec<int> E(6),L(6);
  int B;
  rep(i,6) {
    cin >> E[i];
  }
  cin >> B;
  int cnt=0;
  rep(i,6) {
    cin >> L[i];
    rep(j,6) {
      cnt += E[j]==L[i];
    }
  }
  if (cnt==6) {
    cnt++;
  } else if (cnt==5) {
    rep(i,6) {
      bool flag = false;
      rep(j,6) {
        if (L[i]==E[j])
          flag = true;
      }
      if (!flag && L[i]==B)
          cnt++;
    }
  }
  int res = 8-cnt;
  if (res>5)
    res = 0;
  print(res);
  return 0;
}
