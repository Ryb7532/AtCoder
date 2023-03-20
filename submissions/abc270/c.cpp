#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i=0; i<(n); i++)
#define rrep(i,n) for (int i=n-1; i>=0; i--)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"


int N, X, Y;
vector<vector<int>> E(2e5 + 1);
vector<int> res;

bool dfs(int n, int p) {
  res.push_back(n);
  if (n == Y)
    return true;
  for (int m: E[n]) {
    if (m == p)
      continue;
    if (dfs(m,n))
      return true;
  }
  res.pop_back();
  return false;
}

int main() {
  cin >> N >> X >> Y;
  rep(i,N-1) {
    int U,V;
    cin >> U >> V;
    E[U].push_back(V);
    E[V].push_back(U);
  }
  dfs(X,0);
  for (int n: res) {
    cout << n << " ";
  }
  cout << endl;
  return 0;
}
