#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); i++)


// Topological Sort
class Tsort {
  int N;
  vector<vector<int>> edge;
  vector<int> indg;
  stack<int> st;

public:
  vector<int> sorted;
  Tsort(int n) : N(n), edge(N), indg(N) {}

  void add_edge(int a, int b) {
    edge[a].push_back(b);
    indg[b]++;
  }

  vector<int> get_edges(int a) { return edge[a]; }

  bool sort() {
    rep(i,N) {
      if (indg[i] == 0)
        st.push(i);
    }
    while (!st.empty()) {
      int u = st.top();
      st.pop();
      sorted.push_back(u);
      for (int v: edge[u]) {
        indg[v]--;
        if (indg[v] == 0)
          st.push(v);
      }
    }
    return sorted.size() == N;
  }

  int &operator[](const int id) { return sorted[id]; }
};
