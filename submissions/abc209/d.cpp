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
  int N,Q;
  cin >> N >> Q;
  vec<vec<int>> E(N);
  rep(_,N-1) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  vec<int> D(N,-1);
  vec<int> P(N,-1);
  queue<pair<int,int>> Que;
  Que.push({0,0});
  while (!Que.empty()) {
    auto f = Que.front();
    Que.pop();
    D[f.first] = f.second;
    for (auto &e: E[f.first]) {
      if (D[e] == -1) {
        Que.push({e,f.second+1});
        P[e] = f.first;
      }
    }
  }
  rep(_,Q) {
    int c,d;
    cin >> c >> d;
    c--; d--;
    int dis = max(D[c],D[d])-min(D[c],D[d]);
    if (dis%2)
      print("Road");
    else
      print("Town");
  }
  return 0;
}
