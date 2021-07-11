#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define vec vector
#define rep(i,n) for (int i=0; i<(n); i++)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define YES "YES"
#define No "No"
#define NO "NO"

int N;
vec<vec<int>> E(1e5);
vec<int> C(1e5);
vec<int> cntC(1e5,0);
set<int> res;

void dfs(int n, int p) {
  if (cntC[C[n]]==0)
    res.insert(n+1);
  cntC[C[n]]++;
  for (auto &e: E[n]) {
    if (e == p)
      continue;
    dfs(e,n);
  }
  cntC[C[n]]--;
  return;
}

int main() {
  cin >> N;
  rep(i,N) {
    cin >> C[i];
    C[i]--;
  }
  int A,B;
  rep(i,N-1) {
    cin >> A >> B;
    A--; B--;
    E[A].push_back(B);
    E[B].push_back(A);
  }
  dfs(0,-1);
  for (auto &e: res)
    print(e);
  return 0;
}
