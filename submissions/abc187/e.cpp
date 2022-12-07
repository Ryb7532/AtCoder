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
  vec<pair<int,int>> Edge(N-1);
  vec<vec<int>> E(N);
  vec<int> D(N);
  vec<ll> C(N,0);
  rep(i,N-1) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    Edge[i] = {a,b};
    E[a].push_back(b);
    E[b].push_back(a);
  }
  D[0] = 0;
  queue<pair<int,int>> q;
  q.push({0,-1});
  while (!q.empty()) {
    auto [i,p] = q.front();
    q.pop();
    for (auto &e: E[i]) {
      if (e == p)
        continue;
      D[e] = D[i]+1;
      q.push({e,i});
    }
  }
  int Q;
  cin >> Q;
  rep(_,Q) {
    int t,e;
    ll x;
    cin >> t >> e >> x;
    e--;
    auto [a,b] = Edge[e];
    if (t == 2)
      swap(a,b);
    if (D[a]<D[b]) {
      C[0] += x;
      x = -x;
      swap(a,b);
    }
    C[a] += x;
  }
  q.push({0,-1});
  while (!q.empty()) {
    auto [i,p] = q.front();
    q.pop();
    for (auto &e: E[i]) {
      if (e == p)
        continue;
      C[e] += C[i];
      q.push({e,i});
    }
  }
  rep(i,N)
    print(C[i]);
  return 0;
}
