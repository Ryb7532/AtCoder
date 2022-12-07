#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int main() {
  int H,W,N;
  cin >> H >> W >> N;
  vector<pair<int,int>> P(N);
  map<int,set<int>> A;
  vector<int> res(N,0);
  vector<int> maxR(H), maxC(W);
  rep(i,N) {
    int r,c,a;
    cin >> r >> c >> a;
    r--; c--;
    P[i] = {r, c};
    A[-a].insert(i);
  }
  for (auto it=A.begin(); it!=A.end(); it++) {
    auto ids = it->second;
    for (int id: ids) {
      int r = P[id].first, c = P[id].second;
      auto m = max(maxR[r], maxC[c])+1;
      res[id] = m;
    }
    for (int id: ids) {
      int r = P[id].first, c = P[id].second;
      maxR[r] = max(maxR[r], res[id]);
      maxC[c] = max(maxC[c], res[id]);
    }
  }
  rep(i,N) {
    print(res[i]-1);
  }
  return 0;
}
