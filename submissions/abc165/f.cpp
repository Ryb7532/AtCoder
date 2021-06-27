#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define rep(i,n) for (int i=0; i<(n); i++)
#define reps(i,s,n) for (int i=(s); i<(n); i++)
#define rep1(i,n) for (int i=1; i<=(n); i++)
#define repr(i,s,n) for (int i=(s)-1; i>=(n); i--)
#define print(a) cout << (a) << endl
#define all(v) v.begin(), v.end()
#define rsort(v) sort(v.rbegin(), v.rend())
const int MN = 200001;
const int INF = 1e9+1;
int N;
int res;
vector<int> a(MN);
vector<int> edge[MN];
vector<int> ans(MN,0);
vector<int> dp(MN,INF);
stack<int> st[MN];


void dfs(int n,int p) {
  auto it = lower_bound(all(dp),a[n]);
  if (*it == INF)
    res++;
  int id = (it-dp.begin());
  st[id].push(dp[id]);
  dp[id] = a[n];
  ans[n] = res;
  for (int e : edge[n]) {
    if (e == p)
      continue;
    dfs(e,n);
  }
  dp[id] = st[id].top();
  st[id].pop();
  if (st[id].empty())
    res--;
  return ;
}

int main() {
  cin >> N;
  rep(i,N) cin >> a[i];
  rep(i,N-1) {
    int u,v;
    cin >> u >> v;
    u--; v--;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  dfs(0,-1);
  rep(i,N) {
    print(ans[i]);
  }
  return 0;
}
