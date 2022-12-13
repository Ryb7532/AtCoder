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
  int N,M;
  cin >> N >> M;
  vector<pair<int,int>> AB(N);
  vector<pair<int,int>> CD(M);
  rep(i,N) {
    cin >> AB[i].first;
  }
  rep(i,N) {
    cin >> AB[i].second;
  }
  rep(i,M) {
    cin >> CD[i].first;
  }
  rep(i,M) {
    cin >> CD[i].second;
  }
  sort(all(AB));
  sort(all(CD));
  multiset<int> Y;
  int i = N-1, j = M-1;
  bool flag = true;
  while (i>=0) {
    if (j<0) {
      auto it = Y.lower_bound(AB[i].second);
      if (it != Y.end()) {
        Y.erase(it);
        i--;
      } else {
        flag = false;
        break;
      }
    } else {
      if (AB[i].first > CD[j].first) {
        auto it = Y.lower_bound(AB[i].second);
        if (it != Y.end()) {
          Y.erase(it);
          i--;
        } else {
          flag = false;
          break;
        }
      } else {
        Y.insert(CD[j].second);
        j--;
      }
    }
  }
  print((flag ? Yes : No));
  return 0;
}
