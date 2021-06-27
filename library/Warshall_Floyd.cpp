#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)


//warshall_floyd
const int MAX_V = 100;
const ll INF = 1e9;
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