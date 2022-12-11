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

const long maxD = 1e18;

int main() {
  int N, M;
  cin >> N >> M;
  vector<pair<pair<int, int>, long>> E(M);
  vector<vector<int>> EofN(N);
  int remove = 0;
  rep(i,M) {
    int A, B;
    long C;
    cin >> A >> B >> C;
    A--; B--;
    E[i] = {{A,B},C};
    EofN[A].push_back(i);
    EofN[B].push_back(i);
  }
  vector<vector<long>> dist(N, vector<long>(N, maxD));
  rep(i,M) {
    int a,b;
    long c;
    a = E[i].first.first;
    b = E[i].first.second;
    c = E[i].second;
    dist[a][b] = c;
    dist[b][a] = c;
  }
  rep(i,N) dist[i][i] = 0;
  rep(k,N) rep(i,N) rep(j,N) dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
  rep(i,M) {
    int a, b;
    long c;
    a = E[i].first.first;
    b = E[i].first.second;
    c = E[i].second;
    if (c > dist[a][b]){
      remove++;
      continue;
    }
    bool require = true;
    for (int edge_id: EofN[a]) {
      if (edge_id == i)
        continue;
      auto edge = E[edge_id].first;
      int bypass = (edge.first == a) ? edge.second : edge.first;
      if (dist[a][b] == dist[a][bypass]+dist[bypass][b])
        require = false;
    }
    if (!require)
      remove++;
  }
  print(remove);
  return 0;
}
