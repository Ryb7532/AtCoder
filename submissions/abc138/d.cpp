#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int N;
vector<vector<int>> Edge(200000);
vector<ll> v(200000, 0);

void dfs(int n, int p) {
  int val = 0;
  if (p>=0) {
    val = v[p];
  }
  v[n]+=val;
  for (auto e: Edge[n]) {
    if (e == p)
      continue;
    dfs(e,n);
  }
}

int main() {
  int Q;
  cin >> N >> Q;
  rep(i,N-1) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    Edge[a].push_back(b);
    Edge[b].push_back(a);
  }
  rep(_,Q) {
    int p,x;
    cin >> p >> x;
    p--;
    v[p]+=x;
  }
  dfs(0,-1);
  cout << v[0];
  rep(i,N-1) {
    cout << " " << v[i+1];
  }
  cout << endl;
  return 0;
}
