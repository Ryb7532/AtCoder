#include <bits/stdc++.h>
using namespace std;
#define MAX_V 1000
#define INF 1000000000000
using Edge = struct{
  int from;
  int to;
  long cost;
};

int V, E;
long d[MAX_V];
vector<Edge> edge;

bool Bellman_Ford(int s) {
  for (int i=1; i<V; i++)
    d[i] = INF;
  d[s] = 0;
  for (int i=0; i<V; i++) {
    for (int j=0; j<E; j++) {
      Edge e = edge[j];
      if (d[e.from] == INF)
        continue;
      if (d[e.to] > d[e.from]+e.cost) {
        d[e.to] = d[e.from] + e.cost;
        if (i == V-1 && e.to == V-1)
          return true;
      }
    }
  }
  return false;
}

int main() {
  cin >> V >> E;
  int a, b;
  long c;
  for (int i=0; i<E; i++) {
    cin >> a >> b >> c;
    a--;
    b--;
    edge.push_back({a, b, -c});
  }
  bool loop = Bellman_Ford(0);
  if (loop)
    cout << "inf\n";
  else
    cout << -d[V-1] << endl;
  return 0;
}
