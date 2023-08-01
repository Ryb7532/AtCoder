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

int main() {
  int N1,N2,M;
  cin >> N1 >> N2 >> M;
  vector<vector<int>> E1(N1), E2(N2);
  rep(_,M) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    if (a >= N1) {
      assert(b >= N1);
      a -= N1; b -= N1;
      E2[a].push_back(b);
      E2[b].push_back(a);
    } else {
      assert(b < N1);
      E1[a].push_back(b);
      E1[b].push_back(a);
    }
  }
  vector<int> D1(N1, -1), D2(N2, -1);
  queue<int> q;
  D1[0] = 0;
  q.push(0);
  while (!q.empty()) {
    int n = q.front();
    q.pop();
    for (int next: E1[n]) {
      if (D1[next] != -1)
        continue;
      D1[next] = D1[n]+1;
      q.push(next);
    }
  }
  D2[N2-1] = 0;
  q.push(N2-1);
  while (!q.empty()) {
    int n = q.front();
    q.pop();
    for (int next: E2[n]) {
      if (D2[next] != -1)
        continue;
      D2[next] = D2[n]+1;
      q.push(next);
    }
  }
  int md1 = 0, md2 = 0;
  rep(i,N1) {
    md1 = max(md1, D1[i]);
  }
  rep(i,N2) {
    md2 = max(md2, D2[i]);
  }
  print(md1+md2+1);
  return 0;
}
