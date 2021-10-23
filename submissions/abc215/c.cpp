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

string S;
int K, N;
vec<string> Dict;
vec<bool> used(8, false);

void dfs(int n, string s) {
  if (n >= N) {
    Dict.push_back(s);
    return;
  }
  rep(i, N) {
    if (used[i])
      continue;
    used[i] = true;
    s.push_back(S[i]);
    dfs(n+1, s);
    used[i] = false;
    s.pop_back();
  }
}


int main() {
  cin >> S >> K;
  N = S.size();
  dfs(0, string());
  sort(all(Dict));
  string p = "";
  for (auto e: Dict) {
    if (p != e) {
      K--;
      p = e;
      if (K == 0)
        break;
    }
  }
  print(p);
  return 0;
}
