#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0; i<(n); i++)

const int MV = 1e5;
int V;
vector<int> edge[MV];
vector<int> res;
vector<int> indg(MV);
stack<int> st; //0 indegree


void init(int e) {
  rep(i,e) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    edge[a].push_back(b);
    indg[b]++;
  }
  rep(i,V) {
    if (indg[i] == 0)
      st.push(i);
  }
}
void tsort() {
  while (!st.empty()) {
    int n = st.top();
    st.pop();
    res.push_back(n);
    for (auto e : edge[n]) {
      indg[e]--;
      if (indg[e] == 0)
        st.push(e);
    }
  }
}
