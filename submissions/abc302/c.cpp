#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)s-1; i>=(int)e; i--)
#define rrep2(i,n) rrep3(i,n,0)
#define rrep(...) GET_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl

int N,M;
vector<string> S;
vector<bool> used(8,false);
vector<int> s;
bool res = false;

void dfs(int n) {
  if (n == N) {
    bool flag = true;
    rep(i,N-1) {
      int diff = 0;
      rep(j,M) {
        if (S[s[i]][j] != S[s[i+1]][j])
          diff++;
      }
      if (diff != 1)
        flag = false;
    }
    if (flag)
      res = true;
    return ;
  }
  rep(i,N) {
    if (used[i])
      continue;
    s.push_back(i);
    used[i] = true;
    dfs(n+1);
    s.pop_back();
    used[i] = false;
  }
}

int main() {
  cin >> N >> M;
  S.resize(N);
  rep(i,N) {
    cin >> S[i];
  }
  dfs(0);
  printyesno(res);
  return 0;
}
