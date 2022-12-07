#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define MAX_V 300
const int INF = 2e9+1;
int V;
long d[MAX_V][MAX_V];

void init() {
  for (int i=0; i<MAX_V; i++)
    for (int j=0; j<MAX_V; j++)
      if (i != j)
        d[i][j] = INF;
}

void warshall_floyd() {
  for (int k=0; k<V; k++)
    for (int i=0; i<V; i++)
      for (int j=0; j<V; j++)
        d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
}

int main() {
  int M, L, Q, A, B, C, s, t;
  cin >> V >> M >> L;
  init();
  for (int i=0; i<M; i++) {
    cin >> A >> B >> C;
    A--; B--;
    d[A][B] = d[B][A] = C;
  }
  warshall_floyd();
  for (int i=0; i<V; i++) {
    for (int j=0; j<V; j++) {
      if (i == j)
        continue;
      if (d[i][j] <= L)
        d[i][j] = 1;
      else
        d[i][j] = INF;
    }
  }
  warshall_floyd();
  cin >> Q;
  for (int i=0; i<Q; i++) {
    cin >> s >> t;
    s--; t--;
    if (d[s][t] == INF)
      cout << -1 << endl;
    else
      cout << d[s][t]-1 << endl;
  }
  return 0;
}
