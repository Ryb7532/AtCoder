#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)e-1; i>=(int)s; i--)
#define rrep2(i,n) rrep3(i,0,n)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl
#define printall(a) for (auto e: a) cout << e << " "; cout << endl

// Task: Longest Common Prefix between S[0:|S|-1] and S[i:|S|-1] (0<=i<|S|)
// Z-Algorithm (O(|S|))
vector<int> z_algorithm(const string &s) {
  int l = s.size();
  vector<int> prefix(l,0);
  for (int i=1, j=0; i<l; i++) {
    if (i + prefix[i-j] < j + prefix[j])
      prefix[i] = prefix[i-j];
    else {
      int k = max(0, j+prefix[j]-i);
      while (i + k < l && s[k] == s[i+k])
        k++;
      prefix[i] = k;
      j = i;
    }
  }
  prefix[0] = l;
  return prefix;
}

// Topological Sort
class Tsort {
  int N;
  vector<vector<int>> edge;
  vector<int> res, indg;
  stack<int> st;

public:
  Tsort(int n) : N(n), indg(N), edge(N) {}

  void add_edge(int a, int b) {
    edge[a].push_back(b);
    indg[b]++;
  }

  vector<int> get_edges(int a) { return edge[a]; }

  bool sort(vector<int> &res) {
    rep(i,N) {
      if (indg[i] == 0)
        st.push(i);
    }
    while (!st.empty()) {
      int u = st.top();
      st.pop();
      res.push_back(u);
      for (int v: edge[u]) {
        indg[v]--;
        if (indg[v] == 0)
          st.push(v);
      }
    }
    return res.size() == N;
  }
};


int main() {
  string S,T;
  cin >> S >> T;
  string s = S;
  while (S.size() < T.size()) S += s;
  int lt = T.size(), ls = S.size();
  auto prefix = z_algorithm(T+"#"+S+S);
  Tsort ts(ls);
  rep(i,ls) {
    if (prefix[lt+1+i] == lt)
      ts.add_edge(i, (i+lt)%ls);
  }
  vector<int> ord;
  if (!ts.sort(ord)) {
    print(-1);
    return 0;
  }
  int res = 0;
  vector<int> dp(ls);
  for (int u: ord) {
    res = max(res, dp[u]);
    for (int v: ts.get_edges(u)) {
      dp[v] = max(dp[v], dp[u]+1);
    }
  }
  print(res);
  return 0;
}