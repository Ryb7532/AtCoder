#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define MAX_V 100
const int INF = 1e7;
int V, M;
int d[MAX_V][MAX_V], f[MAX_V][MAX_V];

void init() {
  for (int i=0; i<MAX_V; i++)
    for (int j=0; j<MAX_V; j++)
      d[i][j] = INF;
}

void warshall_floyd() {
  for (int k=0; k<V; k++) {
    for (int i=0; i<V; i++) {
      for (int j=0; j<V; j++) {
        d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
      }
    }
  }
}

int main() {
  cin >> V >> M;
  int A, B, C, ans = 0;
  init();
  for (int i=0; i<M; i++) {
    cin >> A >> B >> C;
    A--;
    B--;
    d[A][B] = d[B][A] = f[A][B] = f[B][A] = C;
  }
  warshall_floyd();
  for (int i=0; i<V; i++)
    for (int j=i+1; j<V; j++)
      if (f[i][j] > d[i][j])
        ans++;
  cout << ans << endl;
  return 0;
}
