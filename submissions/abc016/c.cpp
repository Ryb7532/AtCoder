#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define print(a) cout << (a) << endl;
#define all(v) v.begin(), v.end()


//warshall_floyd
const int MAX_V = 10;
const int INF = 1e9;
int V;
ll d[MAX_V][MAX_V];

void init() {
  rep(i, V)
    rep(j, V)
      if (i != j)
        d[i][j] = INF;
}

void warshall_floyd() {
  rep(k, V)
    rep(i, V)
      rep(j, V)
        d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
}

int main() {
  int M, A, B;
  cin >> V >> M;
  init();
  rep(i, M) {
    cin >> A >> B;
    A--; B--;
    d[A][B] = d[B][A] = 1;
  }
  warshall_floyd();
  rep(i, V) {
    int ans = 0;
    rep(j, V) {
      if (d[i][j] == 2)
        ans++;
    }
    print(ans);
  }
  return 0;
}
