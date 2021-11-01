#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"



const int MV = 1e6;
int V;
vector<int> edge[MV];
vector<int> res;
vector<int> indg(MV);
set<int> st; //0 indegree


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
      st.insert(i);
  }
}
void tsort() {
  while (!st.empty()) {
    auto it = st.begin();
    st.erase(it);
    int n = *it;
    res.push_back(n);
    for (auto e : edge[n]) {
      indg[e]--;
      if (indg[e] == 0)
        st.insert(e);
    }
  }
}


int main() {
  int M;
  cin >> V >> M;
  init(M);
  tsort();
  if (res.size() != V) {
    print(-1);
    return 0;
  }
  stringstream ss;
  for (auto e: res) {
    ss << e+1 << ' ';
  }
  string ans = ss.str();
  ans.pop_back();
  print(ans);
  return 0;
}
