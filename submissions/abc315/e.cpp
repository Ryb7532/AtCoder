#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define GES_MACRO(_1,_2,_3,NAME,...) NAME
#define rep3(i,s,e) for (int i=(int)s; i<(int)e; i++)
#define rep2(i,n) rep3(i,0,n)
#define rep(...) GES_MACRO(__VA_ARGS__,rep3,rep2)(__VA_ARGS__)
#define rrep3(i,s,e) for (int i=(int)s-1; i>=(int)e; i--)
#define rrep2(i,n) rrep3(i,n,0)
#define rrep(...) GES_MACRO(__VA_ARGS__,rrep3,rrep2)(__VA_ARGS__)
#define print(a) cout << a << endl
#define fix(n) fixed << setprecision(n)
#define fill_c(c, n) setfill(c) << setw(n)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define Yes "Yes"
#define No "No"
#define printyesno(f) cout << (f ? Yes : No) << endl

int main() {
  int N;
  cin >> N;
  vector<vector<int>> P(N), Q(N);
  rep(i,N) {
    int C;
    cin >> C;
    P[i].resize(C);
    rep(j,C) {
      cin >> P[i][j];
      P[i][j]--;
      Q[P[i][j]].push_back(i);
    }
  }
  vector<bool> need(N, false);
  set<int> S;
  S.insert(0);
  while (!S.empty()) {
    int top = *S.begin();
    S.erase(top);
    need[top] = true;
    for (int p: P[top]) {
      if (!need[p] && S.find(p) == S.end())
        S.insert(p);
    }
  }
  need[0] = false;
  vector<int> ind(N);
  queue<int> zeroind;
  rep(i,N) {
    ind[i] = P[i].size();
    if (ind[i] == 0 && need[i])
      zeroind.push(i);
  }
  while (!zeroind.empty()) {
    int top = zeroind.front();
    zeroind.pop();
    cout << top + 1 << " ";
    for (int p: Q[top]) {
      ind[p]--;
      if (ind[p] == 0 && need[p])
        zeroind.push(p);
    }
  }
  cout << endl;
  return 0;
}