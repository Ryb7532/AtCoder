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

const int MAX_V = 400;
const ll INF = 1e9;
int V;
ll d[MAX_V][MAX_V];
ll res = 0;

void init() {
  rep(i, V)
    rep(j, V)
      if (i != j)
        d[i][j] = INF;
}

void warshall_floyd() {
  rep(k, V)
    rep(i, V)
      rep(j, V) {
        d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
        if (d[i][j] != INF)
          res += d[i][j];
      }
}

int main() {
  int M;
  cin >> V >> M;
  init();
  rep(_,M) {
    int A,B;
    ll C;
    cin >> A >> B >> C;
    A--; B--;
    d[A][B] = C;
  }
  warshall_floyd();
  print(res);
  return 0;
}
