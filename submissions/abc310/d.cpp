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

int N,T,M;
vector<set<int>> hate(10);
vector<int> team_of(10, -1);
ll res = 0;

void dfs(int n, int t) {
  if (n == N) {
    if (t == T) {
      res++;
    }
    return ;
  }
  vector<bool> candidate_team(t, true);
  for (auto m: hate[n]) {
    candidate_team[team_of[m]] = false;
  }
  rep(i,t) {
    if (!candidate_team[i])
      continue;
    team_of[n] = i;
    dfs(n+1, t);
    team_of[n] = -1;
  }
  team_of[n] = t;
  dfs(n+1, t+1);
  team_of[n] = -1;
  return ;
}

int main() {
  cin >> N >> T >> M;
  rep(i,M) {
    int A,B;
    cin >> A >> B;
    A--;
    B--;
    hate[B].insert(A);
  }
  dfs(0,0);
  print(res);
  return 0;
}
