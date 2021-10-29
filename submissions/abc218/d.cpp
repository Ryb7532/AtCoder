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
  int N;
  cin >> N;
  vec<pair<int,int>> V(N);
  map<int, set<int>> X, Y;
  rep(i,N) {
    cin >> V[i].first >> V[i].second;
    X[V[i].first].insert(V[i].second);
    Y[V[i].second].insert(V[i].first);
  }
  int res = 0;
  rep(i,N) {
    auto p1 = V[i];
    auto x_ = X[p1.first];
    auto y_ = Y[p1.second];
    for (int j=i+1; j<N; j++) {
      auto p2 = V[j];
      if (p2.first == p1.first || p2.second == p1.second)
        continue;
      auto p3 = x_.find(p2.second);
      auto p4 = y_.find(p2.first);
      if (p3 == x_.end())
        continue;
      if (p4 == y_.end())
        continue;
      res++;
    }
  }
  print(res/2);
  return 0;
}
