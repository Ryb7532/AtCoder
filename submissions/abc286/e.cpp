#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"
#define printYorN(f) cout << (f ? Yes : No) << endl


// Task: All Pair Shortest Path Problem
// Warshall-Floyd Algorithm
const int MAX_V = 300;
const ll INF = 1e9;
int V;
pair<ll,ll> d[MAX_V][MAX_V];

template <typename T, typename U>
pair<T,U> operator+(const pair<T,U> &p1, const pair<T,U> &p2) {
  return {p1.first+p2.first, p1.second+p2.second};
}

void init() {
  rep(i, V)
    rep(j, V)
      if (i != j)
        d[i][j] = {INF, 0};
}

void warshall_floyd() {
  rep(k, V)
    rep(i, V)
      rep(j, V)
        d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
}

int main() {
  cin >> V;
  init();
  vector<ll> A(V);
  rep(i,V) {
    cin >> A[i];
  }
  rep(i,V) {
    string S;
    cin >> S;
    rep(j,V) {
      if (S[j] == 'Y')
        d[i][j] = {1, -A[i]};
    }
  }
  warshall_floyd();
  int Q;
  cin >> Q;
  rep(_,Q) {
    int u,v;
    cin >> u >> v;
    u--; v--;
    if (d[u][v].first == INF)
      print("Impossible");
    else
      print(d[u][v].first << " " << -d[u][v].second+A[v]);
  }
  return 0;
}
