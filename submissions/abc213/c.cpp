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
  int H,W,N;
  cin >> H >> W >> N;
  set<pair<int,int>> C,R;
  vec<pair<int,int>> res(N);
  rep(i, N) {
    int A,B;
    cin >> A >> B;
    C.insert({A,i});
    R.insert({B,i});
  }
  int p=0, i=0;
  for (auto e: C) {
    if (p != e.first) {
      i++;
      p = e.first;
    }
    res[e.second].first = i;
  }
  p=0, i=0;
  for (auto e: R) {
    if (p != e.first) {
      i++;
      p = e.first;
    }
    res[e.second].second = i;
  }
  rep(i, N) {
    print(res[i].first << ' ' << res[i].second);
  }
  return 0;
}
