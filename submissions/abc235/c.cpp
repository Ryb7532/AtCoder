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
  int N,Q;
  cin >> N >> Q;
  map<int,vector<int>> m;
  rep(i,N) {
    int a;
    cin >> a;
    if (m.find(a) == m.end()) {
      m[a] = vector<int>();
    }
    m[a].push_back(i);
  }
  rep(_,Q) {
    int x,k;
    cin >> x >> k;
    if (m.find(x) == m.end() || m[x].size() < k) {
      print(-1);
      continue;
    }
    print(m[x][--k]+1);
  }
  return 0;
}
