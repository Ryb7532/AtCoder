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


int N, M;
int maxU;
vector<string> S(8);
set<string> T;
vector<bool> used(8);
vector<string> X;
string res = "-1";
void dfs(int n, int u) {
  if (n == 0) {
    rep(i,N) {
      X.push_back(S[i]);
      used[i] = true;
      dfs(n+1, 0);
      used[i] = false;
      X.pop_back();
    }
  } else if (n == N) {
    string Y;
    for (string s: X) {
      Y += s;
    }
    if (T.find(Y) == T.end())
      res = Y;
  } else {
    if (u < maxU) {
      X.push_back("_");
      dfs(n, u+1);
      X.pop_back();
    }
    rep(i,N) {
      if (used[i])
        continue;
      X.push_back("_" + S[i]);
      used[i] = true;
      dfs(n+1, u);
      used[i] = false;
      X.pop_back();
    }
  }
}

int main() {
  cin >> N >> M;
  maxU = 16 - (N-1);
  rep(i,N) {
    cin >> S[i];
    maxU -= S[i].size();
  }
  rep(_,M) {
    string t;
    cin >> t;
    T.insert(t);
  }
  if (N == 1 && S[0].size() < 3) {
    print(-1);
    return 0;
  }
  dfs(0,0);
  print(res);
  return 0;
}
