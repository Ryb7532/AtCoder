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
vec<set<int>> E(200000);
string res;

void dfs(int n, int p) {
  res += to_string(n+1) + " ";
  for (auto child: E[n]) {
    if (child == p)
      continue;
    dfs(child, n);
    res += to_string(n+1) + " ";
  }
}


int main() {
  cin >> N;
  rep(i,N-1) {
    int A,B;
    cin >> A >> B;
    A--; B--;
    E[A].insert(B);
    E[B].insert(A);
  }
  dfs(0, -1);
  res.pop_back();
  print(res);
  return 0;
}
